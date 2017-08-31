#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "ilist.h"
#include "allowexec.h"
#include "hexdump.h"

extern void qs(ilist* list);

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

void ilist_append_array(ilist* list, const int* array, int n) {
    for (int i = 0; i != n; ++i) {
        ilist_push(list, ielt_new(array[i]));
    }
}

unsigned ilist_checksum(const ilist* list) {
    unsigned sum = 0;
    for (const ielt* ie = list->head; ie; ie = ie->next) {
        sum += (unsigned) ie->i;
    }
    return sum;
}

int ilist_is_sorted(const ilist* list) {
    if (list->head) {
        int last_i = list->head->i;
        for (const ielt* ie = list->head->next; ie; ie = ie->next) {
            if (ie->i < last_i) {
                return 0;
            }
            last_i = ie->i;
        }
    }
    return 1;
}

void ilist_print(const ilist* list) {
    printf("[");
    const ielt* ie = list->head;
    for (int i = 0; ie && i < 20; ++i, ie = ie->next) {
        printf(i ? " %d" : "%d", ie->i);
    }
    if (ie) {
        printf("...");
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
            fprintf(stderr, "Usage: ./testqsx [-r|-u|-d|-m] [-n] [SIZE]\n");
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
    ilist list;
    ilist_initialize(&list);
    ilist_append_array(&list, array, size);

    unsigned original_checksum = ilist_checksum(&list);
    ilist_print(&list);

    if (!no_execute) {
        qs(&list);

        ilist_print(&list);

        // check that the array is sorted
        assert(ilist_is_sorted(&list));
        // check that the sorted array contains the same data
        // (this can be fooled, but it's better than nothing!)
        assert(ilist_checksum(&list) == original_checksum);
    }

    ilist_free(&list);
    free(array);
}
