#ifndef C51_EMU_CPU_H
#define C51_EMU_CPU_H

#include <c51_memory.h>
#include <ihxstream.h>
#include <map>

#define __NOP__                 0x00

///////////////////////////////////////

#define __MOV_R0_DATA__         0x78
#define __MOV_R1_DATA__         0x79
#define __MOV_R2_DATA__         0x7A
#define __MOV_R3_DATA__         0x7B
#define __MOV_R4_DATA__         0x7C
#define __MOV_R5_DATA__         0x7D
#define __MOV_R6_DATA__         0x7E
#define __MOV_R7_DATA__         0x7F

#define __MOV_A_R0__            0xE8
#define __MOV_A_R1__            0xE9
#define __MOV_A_R2__            0xEA
#define __MOV_A_R3__            0xEB
#define __MOV_A_R4__            0xEC
#define __MOV_A_R5__            0xED
#define __MOV_A_R6__            0xEE
#define __MOV_A_R7__            0xEF

#define __MOV_R0_A__            0xF8
#define __MOV_R1_A__            0xF9
#define __MOV_R2_A__            0xFA
#define __MOV_R3_A__            0xFB
#define __MOV_R4_A__            0xFC
#define __MOV_R5_A__            0xFD
#define __MOV_R6_A__            0xFE
#define __MOV_R7_A__            0xFF

#define __MOV_A_DATA__          0x74

#define __MOV_A_DIRECT__        0xE5

#define __MOV_R0_DIRECT__       0xA8
#define __MOV_R1_DIRECT__       0xA9
#define __MOV_R2_DIRECT__       0xAA
#define __MOV_R3_DIRECT__       0xAB
#define __MOV_R4_DIRECT__       0xAC
#define __MOV_R5_DIRECT__       0xAD
#define __MOV_R6_DIRECT__       0xAE
#define __MOV_R7_DIRECT__       0xAF

#define __MOV_DIRECT_A__        0xF5

#define __MOV_DIRECT_R0__       0x88
#define __MOV_DIRECT_R1__       0x89
#define __MOV_DIRECT_R2__       0x8A
#define __MOV_DIRECT_R3__       0x8B
#define __MOV_DIRECT_R4__       0x8C
#define __MOV_DIRECT_R5__       0x8D
#define __MOV_DIRECT_R6__       0x8E
#define __MOV_DIRECT_R7__       0x8F

#define __MOV_DIRECT_DIRECT__   0x85

#define __MOV_DIRECT_DATA__     0x75

#define __MOV_AT_R0_DATA__      0x76
#define __MOV_AT_R1_DATA__      0x77

#define __MOV_A_AT_R0__         0xE6
#define __MOV_A_AT_R1__         0xE7

#define __MOV_AT_R0_A__         0xF6
#define __MOV_AT_R1_A__         0xF7

#define __MOV_AT_R0_DIRECT__    0xA6
#define __MOV_AT_R1_DIRECT__    0xA7

#define __MOV_DIRECT_AT_R0__    0x86
#define __MOV_DIRECT_AT_R1__    0x87

#define __MOV_DPTR_DATA16__     0x90

#define __MOV_C_BITADDR__       0xA2

#define __MOV_BITADDR_C__       0x92


#define __MOVC_A_AT_A_DPTR__    0x93

#define __MOVC_A_AT_A_PC__      0x83

///////////////////////////////////////

#define __MOVX_AT_DPTR_A__      0xF0

#define __MOVX_AT_R0_A__        0xF2
#define __MOVX_AT_R1_A__        0xF3

#define __MOVX_A_AT_DPTR__      0xE0

#define __MOVX_A_AT_R0__        0xE2
#define __MOVX_A_AT_R1__        0xE3

///////////////////////////////////////

#define __ACALL_PAGE0__         0x11
#define __ACALL_PAGE1__         0x31
#define __ACALL_PAGE2__         0x51
#define __ACALL_PAGE3__         0x71
#define __ACALL_PAGE4__         0x91
#define __ACALL_PAGE5__         0xB1
#define __ACALL_PAGE6__         0xD1
#define __ACALL_PAGE7__         0xF1

///////////////////////////////////////

#define __LJMP__                0x02

///////////////////////////////////////

#define __LCALL__               0x12

///////////////////////////////////////

#define __RET__                 0x22

///////////////////////////////////////

#define __AJMP_PAGE0__          0x01
#define __AJMP_PAGE1__          0x21
#define __AJMP_PAGE2__          0x41
#define __AJMP_PAGE3__          0x61
#define __AJMP_PAGE4__          0x81
#define __AJMP_PAGE5__          0xA1
#define __AJMP_PAGE6__          0xC1
#define __AJMP_PAGE7__          0xE1

///////////////////////////////////////

class c51_cpu;

typedef uint8_t (*ins_exec_t)(c51_cpu &, ...);
typedef void (*by_exec_t)(uint8_t instruction, c51_cpu*, ...);

class c51_cpu
{
private:
    ihxstream ihx_file;
    uint64_t cur_time = 0;
    std::map < uint8_t, ins_exec_t > instruction_set;

    /// this function is called on every clock
    void clock_invocation();

public:
    memory c51_memory;

    /// get code memory
    [[nodiscard]] uint8_t get_code(uint16_t code_addr) const { return ihx_file.get_code(code_addr); }

    /// get program counter
    [[nodiscard]] uint16_t get_pc() const { return ihx_file.get_pc(); }

    void reset_pc(uint16_t PC) { ihx_file.reset(PC); }

    explicit c51_cpu(const std::string & filename);

    uint64_t exec(by_exec_t before_exec = nullptr,
                 by_exec_t after_exec = nullptr);
};

#endif //C51_EMU_CPU_H
