#include <stdio.h>
#include <stdlib.h>
#include "hexdump.h"

void f(void) {
    char ch = 'A';
    fprintf(stderr, "%c\n", ch);
}


int main(int argc, char** argv) {
    (void) argc, (void) argv;
    f();
}
