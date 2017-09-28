#include <stdio.h>
#include <stdlib.h>
#include "hexdump.h"

int add(int a, int b) {
    return a + b;
}

int main(int argc, char* argv[]) {
    hexdump(add, 4);

    if (argc <= 2) {
        fprintf(stderr, "Usage: add A B\n\
    Prints A + B.\n");
        exit(1);
    }

    int a = strtol(argv[1], 0, 0);
    int b = strtol(argv[2], 0, 0);
    printf("%d + %d = %d\n", a, b, add(a, b));
}
