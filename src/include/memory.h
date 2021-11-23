#ifndef C51_EMU_MEMORY_H
#define C51_EMU_MEMORY_H

#include <cstdint>

#define __8BIT_ADDR_RELOCATE__(addr) c51_memory + addr

class memory
{
    uint8_t c51_memory [256]{};

public:
    uint8_t * register_0 = __8BIT_ADDR_RELOCATE__(0x00);    // 00H - 07H
    uint8_t * register_1 = __8BIT_ADDR_RELOCATE__(0x08);    // 08H - 0FH
    uint8_t * register_2 = __8BIT_ADDR_RELOCATE__(0x10);    // 10H - 17H
    uint8_t * register_3 = __8BIT_ADDR_RELOCATE__(0x18);    // 18H - 1FH

    uint8_t * acc_A = __8BIT_ADDR_RELOCATE__(0xE0);
    uint8_t * abr_B = __8BIT_ADDR_RELOCATE__(0xF0);

    uint8_t * io_P0 = __8BIT_ADDR_RELOCATE__(0x80);
    uint8_t * io_P1 = __8BIT_ADDR_RELOCATE__(0x90);
    uint8_t * io_P2 = __8BIT_ADDR_RELOCATE__(0xA0);
    uint8_t * io_P3 = __8BIT_ADDR_RELOCATE__(0xB0);

    uint8_t * stack_pointer = __8BIT_ADDR_RELOCATE__(0x81);

    uint8_t * pwr_mng_reg_PCON = __8BIT_ADDR_RELOCATE__(0x87);
    uint8_t * proc_stat_wd_PSW = __8BIT_ADDR_RELOCATE__(0xD0);

    uint8_t * DPL = __8BIT_ADDR_RELOCATE__(0x82);
    uint8_t * DPH = __8BIT_ADDR_RELOCATE__(0x83);
    uint8_t * DPTR = __8BIT_ADDR_RELOCATE__(0x82);

    uint8_t * IP = __8BIT_ADDR_RELOCATE__(0xB8);
    uint8_t * IE = __8BIT_ADDR_RELOCATE__(0xA8);

    uint8_t * SBUF = __8BIT_ADDR_RELOCATE__(0x99);
};

#undef __8BIT_ADDR_RELOCATE__

#endif //C51_EMU_MEMORY_H
