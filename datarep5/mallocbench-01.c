#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char** argv) {
    unsigned long nalloc = 1048576;
    unsigned long allocsz = 1;
    if (argc >= 2) {
        nalloc = strtoul(argv[1], NULL, 0);
    }
    if (argc >= 3) {
        allocsz = strtoul(argv[2], NULL, 0);
    }

    // allocate memory
    char** ptrs = (char**) malloc(sizeof(char*) * nalloc);
    for (unsigned long i = 0; i != nalloc; ++i) {
        ptrs[i] = (char*) malloc(allocsz);
    }

    // touch memory
    for (unsigned long i = 0; i != nalloc; ++i) {
        memset(ptrs[i], 1, allocsz);
    }

    // print pointer values
    printf("ptrs = %p, ptrs[0] = %p", ptrs, ptrs[0]);
    if (nalloc > 1) {
        printf(", ptrs[1] = %p", ptrs[1]);
    }
    printf("\n");

    // free memory
    for (unsigned long i = 0; i != nalloc; ++i) {
        free(ptrs[i]);
    }
    free(ptrs);
}
