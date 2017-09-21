#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char** argv) {
    unsigned long nalloc = 1048576;
    unsigned long allocsz = 1;
    if (argc >= 2) {
        nalloc = strtoul(argv[1], NULL, 0);
    }
    if (argc >= 3) {
        allocsz = strtoul(argv[2], NULL, 0);
    }

    // allocate memory
    char** ptrs = (char**) malloc(sizeof(char*) * nalloc);
    for (unsigned long i = 0; i != nalloc; ++i) {
        ptrs[i] = (char*) malloc(allocsz);
    }

    // touch memory
    for (unsigned long i = 0; i != nalloc; ++i) {
        memset(ptrs[i], 1, allocsz);
    }

    // print pointer values
    printf("ptrs = %p, ptrs[0] = %p", ptrs, ptrs[0]);
    if (nalloc > 1) {
        printf(", ptrs[1] = %p", ptrs[1]);
    }
    printf("\n");

    // print resource usage
    struct rusage ru;
    int r = getrusage(RUSAGE_SELF, &ru);
    assert(r != -1);
    printf("memory used: %ld\n", ru.ru_maxrss * 1024);

    // free memory
    for (unsigned long i = 0; i != nalloc; ++i) {
        free(ptrs[i]);
    }
    free(ptrs);

    // print memory map (Linux only)
    char buf[BUFSIZ];
    sprintf(buf, "/proc/%d/maps", getpid());
    FILE* mapsf = fopen(buf, "r");
    if (mapsf) {
        printf("memory map:\n");
        while (fgets(buf, sizeof(buf), mapsf)) {
            printf("%s", buf);
        }
        fclose(mapsf);
    }
}
