//! -O1

extern unsigned long long a;
extern int b;

int sum(void) {
    return (a & 0xFFFFFFFF) + b;
}
