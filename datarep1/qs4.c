#include <stdlib.h>

static void qs_helper(int* array, int* spare1, int* spare2, int n) {
    if (n > 1) {
        // partition
        int pivot = array[0];
        int nleft = 0, nright = 0;
        for (int i = 1; i < n; ++i) {
            if (array[i] <= pivot) {
                spare1[nleft] = array[i];
                ++nleft;
            } else {
                spare2[nright] = array[i];
                ++nright;
            }
        }

        // move back into `array`
        for (int i = 0; i < nleft; ++i) {
            array[i] = spare1[i];
        }
        array[nleft] = pivot;
        for (int i = 0; i < nright; ++i) {
            array[nleft + 1 + i] = spare2[i];
        }

        // recurse
        qs_helper(&array[0], spare1, spare2, nleft);
        qs_helper(&array[nleft + 1], spare1, spare2, nright);
    }
}

void qs(int* array, int n) {
    int* spare1 = (int*) malloc(sizeof(int) * n);
    int* spare2 = (int*) malloc(sizeof(int) * n);
    qs_helper(array, spare1, spare2, n);
    free(spare1);
    free(spare2);
}
