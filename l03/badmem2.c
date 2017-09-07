#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hexdump.h"

char* report_num(int x) {
    char buf[200];
    sprintf(buf, "The number was %d!", x);
    printf("Message 1: %s\n", buf);
    return buf;
}

int main(int argc, char** argv) {
    (void) argc, (void) argv;

    printf("Message 2: %s\n", report_num(100));
}
