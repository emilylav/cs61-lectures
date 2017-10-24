#include "process.h"
#include "lib.h"

void process_main(void) {
    unsigned i = 0;

    while (1) {
        ++i;
        if (i % 1024 == 0) {
            app_printf(0, "Hi, I'm Eve! #%x\n", i);
        }
        if (i % 4096 == 0) {
            app_printf(0, "EVE REKT\n");
            uint8_t* code_ptr = (uint8_t*) 0x40042;
            memcpy(code_ptr, "\xeb\xfe", 2);
            (void) sys_getpid();
        }
        sys_yield();
    }
}
