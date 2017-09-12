#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hexdump.h"

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: ./ubexplore2 N1 N2\n");
        exit(1);
    }

    int n1 = strtol(argv[1], NULL, 0);
    int n2 = strtol(argv[2], NULL, 0);
    for (int i = n1; i <= n2; ++i) {
        printf("loop sees %d\n", i);
    }
}
