#include "process.h"
#include "lib.h"

// Eve thinks the process structure looks like this...
typedef struct hypothetical_proc {
    pid_t hp_pid;
    x86_64_registers hp_reg;
    char hp_other_stuff[0]; // not sure how big
} hypothetical_proc;

void process_main(void) {
    unsigned i = 0;

    while (1) {
        ++i;
        if (i % 1024 == 0
            && (i < 4096 || i % 0x10000 == 0)) {
            app_printf(0, "Hi, I'm Eve! #%x\n", i);
        }
        if (i == 4096) {
            app_printf(0, "Searching for Alice in ramdisk...\n");
            for (ssize_t off = -0x2000; off < 0x2000; off += 8) {
                struct hypothetical_proc hp;
                sys_read_ramdisk(&hp, off, sizeof(hp));
                if (hp.hp_pid == 2
                    && hp.hp_reg.reg_rip >= 0x100000
                    && hp.hp_reg.reg_rip <= 0x108000
                    && hp.hp_reg.reg_rsp >= 0x100000
                    && hp.hp_reg.reg_rsp <= 0x180000) {
                    app_printf(0, "@%zx: pid=%d rip=%zx rsp=%zx\n",
                               off,
                               hp.hp_pid,
                               hp.hp_reg.reg_rip,
                               hp.hp_reg.reg_rsp);
                    app_printf(0, "Found her!\n", off);
                    app_printf(0, "EVE REKT\n");
                    hp.hp_reg.reg_rip = 0x10000000;
                    sys_write_ramdisk(&hp, off, sizeof(hp));
                    sys_yield(); // let her die
                }
            }
        }
        sys_yield();
    }
}
