#ifndef C51_EMU_CPU_H
#define C51_EMU_CPU_H

#include <c51_memory.h>
#include <ihxstream.h>
#include <map>

#define __NOP__                 0x00

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

class c51_cpu;

typedef uint8_t (*ins_exec_t)(memory &, ...);
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

    explicit c51_cpu(const std::string & filename);

    uint8_t exec(by_exec_t before_exec = nullptr,
                 by_exec_t after_exec = nullptr);
};

#endif //C51_EMU_CPU_H
