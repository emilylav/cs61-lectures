#include "helpers.h"

int main(void) {
    pid_t p1 = fork();
    assert(p1 >= 0);

    printf("Hello from pid %d\n", getpid());
}
