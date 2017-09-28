//! -O1
#include <assert.h>

struct matrix {
    int nrows;
    int ncols;
    int** a;
};

int mget(struct matrix* m, int i, int j) {
    assert(i < m->nrows);
    assert(j < m->ncols);
    return m->a[i][j];
}
