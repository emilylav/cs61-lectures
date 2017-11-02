#include "helpers.h"

int main(void) {
    char* args[] = {
        "./myecho", // argv[0] is the string used to execute the program
        "Hello!",
        "Myecho should print these",
        "arguments.",
        NULL
    };
    fprintf(stderr, "About to exec myecho from pid %d\n", getpid());

    int r = execv("./myecho", args);

    fprintf(stderr, "Finished execing myecho from pid %d; status %d\n",
            getpid(), r);
}
