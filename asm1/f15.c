//! -O1

extern unsigned long a;
extern int b;

int sum(void) {
    // least significant 32 bits of a, as a 32 bit quantity:
    return (a & 0xFFFFFFFF) + b;
}
