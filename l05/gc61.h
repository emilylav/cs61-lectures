#ifndef CS61_M61_H
#define CS61_M61_H
#include <stddef.h>

void* m61_malloc(size_t sz);
void m61_free(void* ptr);

extern char* stack_bottom;
void m61_print_allocations(void);
void m61_cleanup(void);

#endif
