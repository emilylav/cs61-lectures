#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hexdump.h"

int signed_increment(int x) {
    assert(x + 1 > x);
    return x + 1;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./ubexplore N\n");
        exit(1);
    }

    int x = strtol(argv[1], NULL, 0);
    printf("signed_increment(%d) = %d\n", x, signed_increment(x));
}
