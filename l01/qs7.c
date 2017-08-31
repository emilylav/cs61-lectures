#include <stdlib.h>

static int compar(const void* a, const void* b) {
    const int* ia = (const int*) a;
    const int* ib = (const int*) b;
    return *ia < *ib ? -1 : (*ia == *ib ? 0 : 1);
}

void qs(int* array, int n) {
    qsort(array, n, sizeof(int), compar);
}
