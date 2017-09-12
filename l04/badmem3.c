#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hexdump.h"

int main(int argc, char** argv) {
    (void) argc, (void) argv;

    int* ptr = (int*) malloc(sizeof(int));
    *ptr = 2;
    free(ptr);
    free(ptr);
}
