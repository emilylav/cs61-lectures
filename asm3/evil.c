#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <string.h>
#include <sys/time.h>

inline ssize_t mywrite(int fd, const void* data, size_t length)
    __attribute__((always_inline));
inline ssize_t mywrite(int fd, const void* data, size_t length) {
    register uintptr_t arg0 asm("rdi") = fd;
    register uintptr_t arg1 asm("rsi") = (uintptr_t) data;
    register uintptr_t arg2 asm("rdx") = length;
    uintptr_t result;
    __asm__ volatile("syscall"
                     : "=a" (result)
                     : "0" (1), "r" (arg0), "r" (arg1), "r" (arg2)
                     : "memory", "cc", "rcx", "r11");
    return result;
}

inline ssize_t mynanosleep(const struct timespec* ts, struct timespec* tsout)
    __attribute__((always_inline));
inline ssize_t mynanosleep(const struct timespec* ts, struct timespec* tsout) {
    register uintptr_t arg0 asm("rdi") = (uintptr_t) ts;
    register uintptr_t arg1 asm("rsi") = (uintptr_t) tsout;
    uintptr_t result;
    __asm__ volatile("syscall"
                     : "=a" (result)
                     : "0" (35), "r" (arg0), "r" (arg1)
                     : "memory", "cc", "rcx", "r11");
    return result;
}

void evil(void) {
    unsigned seed = 0;
    char buf[80];
    struct timespec wait = {0, 0};
    while (1) {
        char* s = buf;
        for (unsigned x = seed % 48; x > 0; --x)
            *s++ = ' ';
        *s++ = 'D';
        *s++ = 'I';
        *s++ = 'E';
        *s++ = '\n';
        mywrite(STDOUT_FILENO, buf, s - buf);
        wait.tv_nsec = 250000000;
        mynanosleep(&wait, 0);
        seed = seed * 1664525 + 1013904223;
    }
}
