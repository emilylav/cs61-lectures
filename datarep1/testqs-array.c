#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "allowexec.h"
#include "hexdump.h"

extern void qs(int* array, int n);

static void iswap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void initialize_up(int* array, int n) {
    for (int i = 0; i < n; ++i) {
        array[i] = i + 1;
    }
}

void initialize_down(int* array, int n) {
    for (int i = 0; i < n; ++i) {
        array[i] = n - i;
    }
}

void initialize_random(int* array, int n) {
    for (int i = 0; i < n; ++i) {
        array[i] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        iswap(&array[i], &array[random() % n]);
    }
}

void initialize_magic(int* array, int n) {
    for (int i = 1; i <= n; ++i) {
        int middle = i / 2;
        array[i - 1] = array[middle];
        array[middle] = i;
    }
}

unsigned array_checksum(const int* array, int n) {
    unsigned sum = 0;
    for (int i = 0; i != n; ++i) {
        sum += (unsigned) array[i];
    }
    return sum;
}

int array_is_sorted(const int* array, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void array_print(const int* array, int n) {
    printf("[");
    for (int i = 0; i < n && i < 20; ++i) {
        printf(i ? " %d" : "%d", array[i]);
    }
    if (n > 20) {
        printf(" ...");
    }
    printf("]\n");
}

int main(int argc, char* argv[]) {
    limit_stack_size(1048576);   // 1MB of stack is enough for anyone!

    // parse command line arguments
    int initialize_type = 'r';
    int no_execute = 0;
    int size = 6;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-r") == 0
            || strcmp(argv[i], "-u") == 0
            || strcmp(argv[i], "-d") == 0
            || strcmp(argv[i], "-m") == 0) {
            initialize_type = argv[i][1];
        } else if (strcmp(argv[i], "-n") == 0) {
            no_execute = 1;
        } else if (strisnumber(argv[i])) {
            size = strtol(argv[i], NULL, 0);
        } else {
            fprintf(stderr, "Usage: ./testqs [-r|-u|-d|-m] [-n] [SIZE]\n");
            exit(1);
        }
    }

    // initialize based on command line argument
    int* array = (int*) malloc(sizeof(int) * size);
    if (initialize_type == 'r') {
        initialize_random(array, size);
    } else if (initialize_type == 'u') {
        initialize_up(array, size);
    } else if (initialize_type == 'd') {
        initialize_down(array, size);
    } else if (initialize_type == 'm') {
        initialize_magic(array, size);
    }

    unsigned original_checksum = array_checksum(array, size);
    array_print(array, size);

    if (!no_execute) {
        qs(array, size);

        array_print(array, size);

        // check that the array is sorted
        assert(array_is_sorted(array, size));
        // check that the sorted array contains the same data
        // (this can be fooled, but it's better than nothing!)
        assert(array_checksum(array, size) == original_checksum);
    }

    free(array);
}
