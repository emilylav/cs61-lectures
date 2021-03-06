#include "iobench.h"

int main() {
    FILE* f = stdin;
    if (isatty(fileno(f))) {
        f = fopen(DATAFILE, "r");
    }
    if (!f) {
        perror("fopen");
        exit(1);
    }

    size_t size = filesize(fileno(f));
    size_t stride = size / 100;
    size_t block_size = 512;
    char* buf = (char*) malloc(block_size);
    double start = tstamp();

    size_t n = 0, pos = 0;
    while (n < size) {
        size_t r = fread(buf, 1, block_size, f);
        if (r == 0 && ferror(f)) {
            perror("fread");
            exit(1);
        } else if (r != block_size) {
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
        fseek(f, pos, SEEK_SET);
    }

    fclose(f);
    report(n, tstamp() - start);
    fprintf(stderr, "\n");
}
