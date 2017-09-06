#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hexdump.h"

const int const_val = 10;
int g = 0;

void f(void) {
    char ch = 'A';
    int* p;
    p = (int*) malloc(sizeof(int));
    *p = 20000;
    fprintf(stderr, "%c %d %d %p %d\n", ch, const_val, g, p, *p);
    fprintf(stderr, "%zu %zu %zu %zu %zu\n", sizeof(ch), sizeof(const_val),
            sizeof(g), sizeof(p), sizeof(*p));
    fprintf(stderr, "%p %p %p %p %p\n", &ch, &const_val, &g, &p, &*p);
}

int main() {
    f();
}
