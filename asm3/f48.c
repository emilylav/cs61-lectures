//! -O1
extern int a, b, x;

int f(void) {
    if (x != 0) {
        return a;
    } else {
        return b;
    }
}
