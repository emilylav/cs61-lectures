#include "iobench.h"
#include <sys/mman.h>

int main() {
    int fd = STDIN_FILENO;
    if (isatty(fd)) {
        fd = open(DATAFILE, O_RDONLY);
    }
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    size_t size = filesize(fd);
    size_t stride = size / 100;
    char* buf = (char*) malloc(1);
    double start = tstamp();

    char* file_data = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
    if (file_data == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    size_t n = 0, pos = 0;
    while (n < size) {
        memcpy(buf, &file_data[pos], 1);
        n += 1;
        if (n % PRINT_FREQUENCY == 0) {
            report(n, tstamp() - start);
        }

        pos += stride;
        if (pos >= size) {
            pos = (pos - size) + 1;
        }
    }

    munmap(file_data, size);
    close(fd);
    report(n, tstamp() - start);
    fprintf(stderr, "\n");
}
