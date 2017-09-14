#include "gc61.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

typedef struct mblock {
    uintptr_t ptr;
    size_t sz;
    int mark;
} mblock;

static mblock* blocks;
static size_t nblocks;
static size_t blocks_capacity;
static mblock* m61_find(void* ptr);
static void m61_gc(void);

char* stack_bottom;

void* m61_malloc(size_t sz) {
    void* ptr = malloc(sz);
    if (!ptr) {
        m61_gc();
        ptr = malloc(sz);
    }
    if (ptr) {
        if (nblocks == blocks_capacity) {
            blocks_capacity = nblocks ? 2 * nblocks : 128;
            blocks = (mblock*)
                realloc(blocks, sizeof(mblock) * blocks_capacity);
            assert(blocks);
        }
        blocks[nblocks].ptr = (uintptr_t) ptr;
        blocks[nblocks].sz = sz;
        ++nblocks;
    }
    return ptr;
}

static mblock* m61_find(void* ptr) {
    if (!ptr) {
        return NULL;
    }
    for (size_t i = 0; i != nblocks; ++i) {
        if ((uintptr_t) ptr >= blocks[i].ptr
            && (uintptr_t) ptr < blocks[i].ptr + blocks[i].sz) {
            return &blocks[i];
        }
    }
    return NULL;
}

void m61_free(void* ptr) {
    if (ptr) {
        mblock* m = m61_find(ptr);
        assert(m && m->ptr == (uintptr_t) ptr);
        *m = blocks[nblocks - 1];
        --nblocks;
    }
    free(ptr);
}

void m61_print_allocations(void) {
    for (size_t i = 0; i != nblocks; ++i) {
        fprintf(stderr, "%p: allocated object with size %zu\n",
                (void*) blocks[i].ptr, blocks[i].sz);
    }
}

void m61_mark_memory(char* base, size_t sz) {
    if (sz < sizeof(void*)
        || (uintptr_t) base + sz < (uintptr_t) base) {
        return;
    }
    for (size_t i = 0; i <= sz - sizeof(void*); ++i) {
        void* possible_ptr;
        memcpy(&possible_ptr, &base[i], sizeof(possible_ptr));
        mblock* m = m61_find(possible_ptr);
        if (m && !m->mark) {
            m->mark = 1;
            m61_mark_memory((char *) m->ptr, m->sz);
        }
    }
}

static void m61_gc(void) {
    assert(stack_bottom);
    char* stack_top = (char*) &stack_top;
    fprintf(stderr, "Collecting garbage (stack [%p,%p))...\n",
            stack_top, stack_bottom);

    // The heap starts out unmarked
    for (size_t i = 0; i != nblocks; ++i) {
        blocks[i].mark = 0;
    }

    // Mark all objects reachable from the stack
    m61_mark_memory(stack_top, stack_bottom - stack_top);

    // Free everything that wasn't marked
    for (size_t i = 0; i != nblocks; ++i) {
        if (!blocks[i].mark) {
            //fprintf(stderr, "%p: freeing unreferenced object with size %zu\n",
            //        (void*) blocks[i].ptr, blocks[i].sz);
            m61_free((void*) blocks[i].ptr);
            --i;                // recheck slot (it has another object now)
        }
    }
}

void m61_cleanup(void) {
    m61_gc();
}
