#include "x86-64.h"
#include "elf.h"
#include "lib.h"
#include "kernel.h"

// k-loader.c
//
//    Load a weensy application into memory from a RAM image.

extern uint8_t _binary_obj_p_eve_start[];
extern uint8_t _binary_obj_p_eve_end[];
extern uint8_t _binary_obj_p_alice_start[];
extern uint8_t _binary_obj_p_alice_end[];
extern uint8_t _binary_obj_p_recurse_start[];
extern uint8_t _binary_obj_p_recurse_end[];

struct ramimage {
    void* begin;
    void* end;
} ramimages[] = {
    { _binary_obj_p_eve_start, _binary_obj_p_eve_end },
    { _binary_obj_p_alice_start, _binary_obj_p_alice_end },
    { _binary_obj_p_recurse_start, _binary_obj_p_recurse_end }
};

static int program_load_segment(proc* p, const elf_program* ph,
                                const uint8_t* src);

// program_load(p, programnumber)
//    Load the code corresponding to program `programnumber` into the process
//    `p` and set `p->p_registers.reg_rip` to its entry point.
//    Assumes memory for `p` is already allocated and mapped.
//    Returns 0 on success and -1 on failure (e.g. out-of-memory).
int program_load(proc* p, int programnumber) {
    // is this a valid program?
    int nprograms = sizeof(ramimages) / sizeof(ramimages[0]);
    assert(programnumber >= 0 && programnumber < nprograms);
    elf_header* eh = (elf_header*) ramimages[programnumber].begin;
    assert(eh->e_magic == ELF_MAGIC);

    // load each loadable program segment into memory
    elf_program* ph = (elf_program*) ((const uint8_t*) eh + eh->e_phoff);
    for (int i = 0; i < eh->e_phnum; ++i) {
        if (ph[i].p_type == ELF_PTYPE_LOAD) {
            const uint8_t* pdata = (const uint8_t*) eh + ph[i].p_offset;
            if (program_load_segment(p, &ph[i], pdata) < 0) {
                return -1;
            }
        }
    }

    // set the entry point from the ELF header
    p->p_registers.reg_rip = eh->e_entry;
    return 0;
}


// program_load_segment(p, ph, src)
//    Load an ELF segment at virtual address `ph->p_va` in process `p`. Copies
//    `[src, src + ph->p_filesz)` to `dst`, then clears
//    `[ph->p_va + ph->p_filesz, ph->p_va + ph->p_memsz)` to 0.
//    Returns 0 on success and -1 on failure.
static int program_load_segment(proc* p, const elf_program* ph,
                                const uint8_t* src) {
    (void) p;
    uintptr_t va = (uintptr_t) ph->p_va;
    uintptr_t end_file = va + ph->p_filesz, end_mem = va + ph->p_memsz;
    va &= ~(PAGESIZE - 1);                // round to page boundary
    memcpy((uint8_t*) va, src, end_file - va);
    memset((uint8_t*) end_file, 0, end_mem - end_file);
    return 0;
}


// program_get_load_address(programnumber)
//    Return the first virtual address in program `programnumber`.
//    Returns (uintptr_t) -1 if `programnumber` is not valid.
uintptr_t program_get_load_address(int programnumber) {
    uintptr_t va = (uintptr_t) -1;
    int nprograms = sizeof(ramimages) / sizeof(ramimages[0]);
    if (programnumber >= 0 && programnumber < nprograms) {
        elf_header* eh = (elf_header*) ramimages[programnumber].begin;
        assert(eh->e_magic == ELF_MAGIC);
        elf_program* ph = (elf_program*) ((const uint8_t*) eh + eh->e_phoff);
        for (int i = 0; i < eh->e_phnum; ++i) {
            if (ph[i].p_type == ELF_PTYPE_LOAD
                && ph[i].p_va < va) {
                va = ph[i].p_va;
            }
        }
    }
    return va;
}
