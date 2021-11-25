#ifndef C51_EMU_C51_MEMORY_H
#define C51_EMU_C51_MEMORY_H

#include <cstdint>

void _8bit_set_bit(uint8_t * addr, int bit_pos, bool bit);
bool _8bit_get_bit(const uint8_t * addr, int bit_pos);

// PSW Register (all 8051 and 251 variants)
#define PSW_P   0
#define PSW_UD  1
#define PSW_OV  2
#define PSW_RS0 3
#define PSW_RS1 4
#define PSW_FO  5
#define PSW_AC  6
#define PSW_CY  7

#define R0      0
#define R1      1
#define R2      2
#define R3      3
#define R4      4
#define R5      5
#define R6      6
#define R7      7


#define __8BIT_ADDR_RELOCATE__(addr) c51_memory + addr

class memory
{
    uint8_t c51_memory [256]{};
    uint8_t c51_xmemory [64 * 1024]{};

public:
    /// get current register bank
    [[nodiscard]] uint8_t * current_bank() const;

    /// locate memory
    [[nodiscard]] uint8_t * locate(uint8_t addr) { return c51_memory + addr; }

    /// locate external memory
    [[nodiscard]] uint8_t * locatex(uint16_t addr) { return c51_xmemory + addr; }

    /// locate bit by address
    /// @param bit_addr bit address
    /// @return bit result
    bool bit_access(uint8_t bit_addr);

    /// modify bit by address
    /// @param bit_addr bit address
    /// @param val value that bit address
    void bit_modify(uint8_t bit_addr, bool val);

    uint8_t * register_bank_0 = __8BIT_ADDR_RELOCATE__(0x00);    // 00H - 07H
    uint8_t * register_bank_1 = __8BIT_ADDR_RELOCATE__(0x08);    // 08H - 0FH
    uint8_t * register_bank_2 = __8BIT_ADDR_RELOCATE__(0x10);    // 10H - 17H
    uint8_t * register_bank_3 = __8BIT_ADDR_RELOCATE__(0x18);    // 18H - 1FH

    uint8_t * acc_A = __8BIT_ADDR_RELOCATE__(0xE0);
    uint8_t * abr_B = __8BIT_ADDR_RELOCATE__(0xF0);

    uint8_t * io_P0 = __8BIT_ADDR_RELOCATE__(0x80);
    uint8_t * io_P1 = __8BIT_ADDR_RELOCATE__(0x90);
    uint8_t * io_P2 = __8BIT_ADDR_RELOCATE__(0xA0);
    uint8_t * io_P3 = __8BIT_ADDR_RELOCATE__(0xB0);

    uint8_t * stack_pointer = __8BIT_ADDR_RELOCATE__(0x81);

    uint8_t * pwr_mng_reg_PCON = __8BIT_ADDR_RELOCATE__(0x87);
    uint8_t * prog_stat_wd_PSW = __8BIT_ADDR_RELOCATE__(0xD0);

    uint8_t * DPL = __8BIT_ADDR_RELOCATE__(0x82);
    uint8_t * DPH = __8BIT_ADDR_RELOCATE__(0x83);
    uint16_t * DPTR = (uint16_t *)__8BIT_ADDR_RELOCATE__(0x82);

    uint8_t * IP = __8BIT_ADDR_RELOCATE__(0xB8);
    uint8_t * IE = __8BIT_ADDR_RELOCATE__(0xA8);

    uint8_t * SBUF = __8BIT_ADDR_RELOCATE__(0x99);
};

#undef __8BIT_ADDR_RELOCATE__

#endif //C51_EMU_C51_MEMORY_H
