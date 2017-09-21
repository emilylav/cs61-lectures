#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include "hexdump.h"

const int const_val = 10;
int g = 0;

int main();

void f(void) {
    char a[5000000];
    char ch = 'A';
    int* p;
    p = (int*) malloc(sizeof(int));
    *p = 20000;
    printf("%c %d %d %p %d\n", ch, const_val, g, p, *p);

    hexdump(&ch, sizeof(ch));
}

int main() {
    f();
}
