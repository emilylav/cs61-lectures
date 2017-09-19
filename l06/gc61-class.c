#include "gc61.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

typedef struct mblock {
    uintptr_t addr;
    size_t sz;
    int mark;
} mblock;

static mblock* blocks;
static size_t nblocks;
static size_t blocks_capacity;
char* stack_bottom;
static void m61_gc(void);

void* m61_malloc(size_t sz) {
    void* ptr = malloc(sz);
    if (!ptr) {
        m61_gc();
        ptr = malloc(sz);
    }
    if (ptr) {
        if (nblocks == blocks_capacity) {
            blocks_capacity = nblocks ? 2 * nblocks : 8192;
            blocks = (mblock*)
                realloc(blocks, sizeof(mblock) * blocks_capacity);
            assert(blocks);
        }
        blocks[nblocks].addr = (uintptr_t) ptr;
        blocks[nblocks].sz = sz;
        ++nblocks;
    }
    return ptr;
}

mblock* m61_find(void* ptr) {
    // returns a pointer to the allocation containing `ptr`
    uintptr_t addr = (uintptr_t) ptr;
    for (size_t i = 0; i != nblocks; ++i) {
        if (addr >= blocks[i].addr
            && addr <= blocks[i].addr + blocks[i].sz) {
            return &blocks[i];
        }
    }
    return NULL;
}

void m61_free(void* ptr) {
    if (ptr) {
        mblock* m = m61_find(ptr);
        *m = blocks[nblocks - 1];
        --nblocks;
        free(ptr);
    }
}

void m61_mark_memory(char* base, size_t sz) {
    // mark every allocation pointed to by [base,base+sz)
    // recursively call m61_mark_memory for every newly-marked
    // allocation.
    char* end = base + sz;
    while (end - base >= sizeof(void*)) {
        void* possible_ptr;
        memcpy(&possible_ptr, base, sizeof(void*));
        mblock* m = m61_find(possible_ptr);
        if (m && !m->mark) {
            m->mark = 1;
            m61_mark_memory((char*) m->addr, m->sz);
        }
        base += sizeof(void*);
    }
}

static void m61_gc(void) {
    // important that `stack_top` be aligned!!
    char* stack_top = (char*) &stack_top;

    for (size_t i = 0; i != nblocks; ++i) {
        blocks[i].mark = 0;
    }

    m61_mark_memory(stack_top, stack_bottom - stack_top);

    size_t nfreed = 0;
    for (size_t i = 0; i != nblocks; ++i) {
        if (!blocks[i].mark) {
            nfreed += blocks[i].sz;
            m61_free((void*) blocks[i].addr);
            --i;
        }
    }

    printf("garbage collected %zu\n", nfreed);
}

void m61_print_allocations(FILE* f) {
    for (size_t i = 0; i != nblocks; ++i) {
        fprintf(f, "%p+%zu\n", (void*) blocks[i].addr,
                blocks[i].sz);
    }
}

void m61_cleanup(void) {
    m61_gc();
}
