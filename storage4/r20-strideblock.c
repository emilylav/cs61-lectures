#include "iobench.h"

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
    size_t block_size = 512;
    char* buf = (char*) malloc(block_size);
    double start = tstamp();

    size_t n = 0, pos = 0;
    while (n < size) {
        ssize_t r = read(fd, buf, block_size);
        if (r == -1) {
            perror("read");
            exit(1);
        } else if (r != (ssize_t) block_size) {
            break;
        }
        n += r;
        if (n % PRINT_FREQUENCY == 0) {
            report(n, tstamp() - start);
        }

        pos += stride;
        if (pos >= size) {
            pos = (pos - size) + block_size;
        }
        lseek(fd, pos, SEEK_SET);
    }

    close(fd);
    report(n, tstamp() - start);
    fprintf(stderr, "\n");
}
