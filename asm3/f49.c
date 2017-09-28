//! -O1
extern int a, b;

int f(int x) {
    if (x != 0) {
        return a;
    } else {
        return b;
    }
}
