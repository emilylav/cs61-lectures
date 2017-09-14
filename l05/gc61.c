#include "gc61.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

typedef struct mblock {
    uintptr_t ptr;
    size_t sz;
} mblock;

static mblock* blocks;
static size_t nblocks;
static size_t blocks_capacity;

void* m61_malloc(size_t sz) {
    void* ptr = malloc(sz);
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

void m61_free(void* ptr) {
    free(ptr);
}

void m61_print_allocations(void) {
}

void m61_cleanup(void) {
}
