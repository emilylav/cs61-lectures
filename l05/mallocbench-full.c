#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <sys/time.h>
#include <sys/resource.h>

static inline void checked_getrusage(int who, struct rusage* usage) {
    int r = getrusage(who, usage);
    if (r == -1) {
        perror("getrusage");
        exit(1);
    }
}

int main(int argc, char** argv) {
    unsigned long nalloc = 1000000;
    unsigned long allocsz = 1;
    if (argc >= 2) {
        nalloc = strtoul(argv[1], NULL, 0);
    }
    if (argc >= 3) {
        allocsz = strtoul(argv[2], NULL, 0);
    }

    // print initial usage
    struct rusage ru;
    checked_getrusage(RUSAGE_SELF, &ru);
    printf("initial reported usage:   %12zd\n",
           ru.ru_maxrss * 1024); // maxrss is measured is measured in KiB

    // allocate memory
    char** ptrs = (char**) malloc(sizeof(char*) * nalloc);
    for (unsigned long i = 0; i != nalloc; ++i) {
        ptrs[i] = (char*) malloc(allocsz);
    }

    // print expected usage and observed usage
    printf("allocated:                %12zu (%zu * %zuB)\n",
           nalloc * allocsz, nalloc, allocsz);
    checked_getrusage(RUSAGE_SELF, &ru);
    printf("allocated reported usage: %12zd\n", ru.ru_maxrss * 1024);

    // touch memory
    for (unsigned long i = 0; i != nalloc; ++i) {
        memset(ptrs[i], 1, allocsz);
    }

    checked_getrusage(RUSAGE_SELF, &ru);
    printf("touched reported usage:   %12zd\n", ru.ru_maxrss * 1024);

    // free memory
    for (unsigned long i = 0; i != nalloc; ++i) {
        free(ptrs[i]);
    }
    free(ptrs);

    checked_getrusage(RUSAGE_SELF, &ru);
    printf("freed reported usage:     %12zd\n", ru.ru_maxrss * 1024);    

    // Linux kernel virtual set size report
    char buf[BUFSIZ];
    sprintf(buf, "/proc/%d/status", getpid());
    FILE* statf = fopen(buf, "r");
    if (statf) {
        while (fgets(buf, sizeof(buf), statf)) {
            unsigned long vsize;
            if (sscanf(buf, "VmSize: %lu kB", &vsize) == 1) {
                printf("virtual memory size:      %12lu\n", vsize * 1024);
            }
        }
    }
    
    // Linux kernel memory map report
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
