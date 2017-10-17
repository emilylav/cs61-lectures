#include "iobench.h"

int main(int argc, char** argv) {
    const char* filename = (argc < 2 ? DATAFILE : argv[1]);
    size_t size = 0;
    size_t stride = 0;
    char* buf = (char*) malloc(1);
    double start = tstamp();

    FILE** fs = (FILE**) malloc(1000 * sizeof(FILE*));
    for (size_t i = 0; size == 0 || i < size / stride; ++i) {
        fs[i] = fopen(filename, "r");
        assert(fs[i]);

        // set file size and stride first time we open
        if (i == 0) {
            size = filesize(fileno(fs[i]));
            stride = size / 100;
            assert(size != 0);
            assert(size % stride == 0);
            assert(size / stride <= 1000);
        }

        fseek(fs[i], stride * i, SEEK_SET);
    }

    size_t n = 0;
    while (n < size) {
        int fileindex = n % (size / stride);
        size_t r = fread(buf, 1, 1, fs[fileindex]);
        if (r == 0 && ferror(fs[fileindex])) {
            perror("read");
            exit(1);
        } else if (r != 1) {
            break;
        }
        n += r;
        if (n % PRINT_FREQUENCY == 0) {
            report(n, tstamp() - start);
        }
    }

    for (size_t i = 0; i < size / stride; ++i) {
        fclose(fs[i]);
    }
    report(n, tstamp() - start);
    fprintf(stderr, "\n");
}
