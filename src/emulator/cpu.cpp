#include <cpu.h>
#include <cstdarg>

#define __EMPLACE_OPERATION__(MARCO, FUNC)   instruction_set.emplace(MARCO, FUNC)

#define __GET_ARGUMENT__(VAL_NAME)          \
    va_list __valist;                       \
    va_start(__valist, 1);                  \
    VAL_NAME = va_arg(__valist, int);       \
    va_end(__valist);                       \
    __asm__("nop")

#define __GET_2_ARGUMENTS__(VAL_NAME1, VAL_NAME2)   \
    va_list __valist;                       \
    va_start(__valist, 2);                  \
    VAL_NAME1 = va_arg(__valist, int);      \
    VAL_NAME2 = va_arg(__valist, int);      \
    va_end(__valist);                       \
    __asm__("nop")

///////////////////////////////////////////////////////////////
/// NOP
///////////////////////////////////////////////////////////////

uint8_t __nop__ (c51_cpu & cpu, ...)
{
    return 1;
}

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
/// MOV Rn, #data
///////////////////////////////////////////////////////////////

uint8_t __mov_r0_data__ (c51_cpu & cpu, ...)
{
    uint8_t data;
    __GET_ARGUMENT__(data);
    cpu.c51_memory.current_bank()[R0] = data;
    return 1;
}

uint8_t __mov_r1_data__ (c51_cpu & cpu, ...)
{
    uint8_t data;
    __GET_ARGUMENT__(data);
    cpu.c51_memory.current_bank()[R1] = data;
    return 1;
}

uint8_t __mov_r2_data__ (c51_cpu & cpu, ...)
{
    uint8_t data;
    __GET_ARGUMENT__(data);
    cpu.c51_memory.current_bank()[R2] = data;
    return 1;
}

uint8_t __mov_r3_data__ (c51_cpu & cpu, ...)
{
    uint8_t data;
    __GET_ARGUMENT__(data);
    cpu.c51_memory.current_bank()[R3] = data;
    return 1;
}

uint8_t __mov_r4_data__ (c51_cpu & cpu, ...)
{
    uint8_t data;
    __GET_ARGUMENT__(data);
    cpu.c51_memory.current_bank()[R4] = data;
    return 1;
}

uint8_t __mov_r5_data__ (c51_cpu & cpu, ...)
{
    uint8_t data;
    __GET_ARGUMENT__(data);
    cpu.c51_memory.current_bank()[R5] = data;
    return 1;
}

uint8_t __mov_r6_data__ (c51_cpu & cpu, ...)
{
    uint8_t data;
    __GET_ARGUMENT__(data);
    cpu.c51_memory.current_bank()[R6] = data;
    return 1;
}

uint8_t __mov_r7_data__ (c51_cpu & cpu, ...)
{
    uint8_t data;
    __GET_ARGUMENT__(data);
    cpu.c51_memory.current_bank()[R7] = data;
    return 1;
}

///////////////////////////////////////////////////////////////
/// MOV A, Rn
///////////////////////////////////////////////////////////////

uint8_t __mov_a_r0__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.acc_A = cpu.c51_memory.current_bank()[R0];
    return 1;
}

uint8_t __mov_a_r1__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.acc_A = cpu.c51_memory.current_bank()[R1];
    return 1;
}

uint8_t __mov_a_r2__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.acc_A = cpu.c51_memory.current_bank()[R2];
    return 1;
}

uint8_t __mov_a_r3__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.acc_A = cpu.c51_memory.current_bank()[R3];
    return 1;
}

uint8_t __mov_a_r4__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.acc_A = cpu.c51_memory.current_bank()[R4];
    return 1;
}

uint8_t __mov_a_r5__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.acc_A = cpu.c51_memory.current_bank()[R5];
    return 1;
}

uint8_t __mov_a_r6__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.acc_A = cpu.c51_memory.current_bank()[R6];
    return 1;
}

uint8_t __mov_a_r7__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.acc_A = cpu.c51_memory.current_bank()[R7];
    return 1;
}

///////////////////////////////////////////////////////////////
/// MOV Rn, A
///////////////////////////////////////////////////////////////

uint8_t __mov_r0_a__ (c51_cpu & cpu, ...)
{
    cpu.c51_memory.current_bank()[R0] = *cpu.c51_memory.acc_A;
    return 1;
}

uint8_t __mov_r1_a__ (c51_cpu & cpu, ...)
{
    cpu.c51_memory.current_bank()[R1] = *cpu.c51_memory.acc_A;
    return 1;
}

uint8_t __mov_r2_a__ (c51_cpu & cpu, ...)
{
    cpu.c51_memory.current_bank()[R2] = *cpu.c51_memory.acc_A;
    return 1;
}

uint8_t __mov_r3_a__ (c51_cpu & cpu, ...)
{
    cpu.c51_memory.current_bank()[R3] = *cpu.c51_memory.acc_A;
    return 1;
}

uint8_t __mov_r4_a__ (c51_cpu & cpu, ...)
{
    cpu.c51_memory.current_bank()[R4] = *cpu.c51_memory.acc_A;
    return 1;
}

uint8_t __mov_r5_a__ (c51_cpu & cpu, ...)
{
    cpu.c51_memory.current_bank()[R5] = *cpu.c51_memory.acc_A;
    return 1;
}

uint8_t __mov_r6_a__ (c51_cpu & cpu, ...)
{
    cpu.c51_memory.current_bank()[R6] = *cpu.c51_memory.acc_A;
    return 1;
}

uint8_t __mov_r7_a__ (c51_cpu & cpu, ...)
{
    cpu.c51_memory.current_bank()[R7] = *cpu.c51_memory.acc_A;
    return 1;
}

///////////////////////////////////////////////////////////////
/// MOV A, #data
///////////////////////////////////////////////////////////////

uint8_t __mov_a_data__ (c51_cpu & cpu, ...)
{
    uint8_t data;
    __GET_ARGUMENT__(data);
    *cpu.c51_memory.acc_A = data;
    return 1;
}

///////////////////////////////////////////////////////////////
/// MOV A, direct addr
///////////////////////////////////////////////////////////////

uint8_t __mov_a_direct__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.acc_A = *cpu.c51_memory.locate(addr);
    return 1;
}

///////////////////////////////////////////////////////////////
/// MOV Rn, direct addr
///////////////////////////////////////////////////////////////

uint8_t __mov_r0_direct__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    cpu.c51_memory.current_bank()[R0] = *cpu.c51_memory.locate(addr);
    return 2;
}

uint8_t __mov_r1_direct__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    cpu.c51_memory.current_bank()[R1] = *cpu.c51_memory.locate(addr);
    return 2;
}

uint8_t __mov_r2_direct__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    cpu.c51_memory.current_bank()[R2] = *cpu.c51_memory.locate(addr);
    return 2;
}

uint8_t __mov_r3_direct__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    cpu.c51_memory.current_bank()[R3] = *cpu.c51_memory.locate(addr);
    return 2;
}

uint8_t __mov_r4_direct__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    cpu.c51_memory.current_bank()[R4] = *cpu.c51_memory.locate(addr);
    return 2;
}

uint8_t __mov_r5_direct__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    cpu.c51_memory.current_bank()[R5] = *cpu.c51_memory.locate(addr);
    return 2;
}

uint8_t __mov_r6_direct__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    cpu.c51_memory.current_bank()[R6] = *cpu.c51_memory.locate(addr);
    return 2;
}

uint8_t __mov_r7_direct__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    cpu.c51_memory.current_bank()[R7] = *cpu.c51_memory.locate(addr);
    return 2;
}

///////////////////////////////////////////////////////////////
/// MOV direct addr, A
///////////////////////////////////////////////////////////////

uint8_t __mov_direct_a__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.locate(addr) = *cpu.c51_memory.acc_A;
    return 1;
}

///////////////////////////////////////////////////////////////
/// MOV direct addr, Rn
///////////////////////////////////////////////////////////////

uint8_t __mov_direct_r0__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.locate(addr) = cpu.c51_memory.current_bank()[R0];
    return 2;
}

uint8_t __mov_direct_r1__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.locate(addr) = cpu.c51_memory.current_bank()[R1];
    return 2;
}

uint8_t __mov_direct_r2__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.locate(addr) = cpu.c51_memory.current_bank()[R2];
    return 2;
}

uint8_t __mov_direct_r3__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.locate(addr) = cpu.c51_memory.current_bank()[R3];
    return 2;
}

uint8_t __mov_direct_r4__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.locate(addr) = cpu.c51_memory.current_bank()[R4];
    return 2;
}

uint8_t __mov_direct_r5__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.locate(addr) = cpu.c51_memory.current_bank()[R5];
    return 2;
}

uint8_t __mov_direct_r6__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.locate(addr) = cpu.c51_memory.current_bank()[R6];
    return 2;
}

uint8_t __mov_direct_r7__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.locate(addr) = cpu.c51_memory.current_bank()[R7];
    return 2;
}

///////////////////////////////////////////////////////////////
/// MOV direct addr, direct addr
///////////////////////////////////////////////////////////////

uint8_t __mov_direct_direct__ (c51_cpu & cpu, ...)
{
    uint8_t addr1, addr2;
    __GET_2_ARGUMENTS__(addr1, addr2);
    *cpu.c51_memory.locate(addr2) = *cpu.c51_memory.locate(addr1);
    return 2;
}

///////////////////////////////////////////////////////////////
/// MOV direct addr, #data
///////////////////////////////////////////////////////////////

uint8_t __mov_direct_data__ (c51_cpu & cpu, ...)
{
    uint8_t data, addr;
    __GET_2_ARGUMENTS__(addr, data);
    *cpu.c51_memory.locate(addr) = data;
    return 2;
}

///////////////////////////////////////////////////////////////
/// MOV @Ri, #data
///////////////////////////////////////////////////////////////

uint8_t __mov_at_r0_data__ (c51_cpu & cpu, ...)
{
    uint8_t data;
    __GET_ARGUMENT__(data);
    *cpu.c51_memory.locate(cpu.c51_memory.current_bank()[R0]) = data;
    return 1;
}

uint8_t __mov_at_r1_data__ (c51_cpu & cpu, ...)
{
    uint8_t data;
    __GET_ARGUMENT__(data);
    *cpu.c51_memory.locate(cpu.c51_memory.current_bank()[R1]) = data;
    return 1;
}

///////////////////////////////////////////////////////////////
/// MOV A, @Ri
///////////////////////////////////////////////////////////////

uint8_t __mov_a_at_r0__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.acc_A = *cpu.c51_memory.locate(cpu.c51_memory.current_bank()[R0]);
    return 1;
}

uint8_t __mov_a_at_r1__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.acc_A = *cpu.c51_memory.locate(cpu.c51_memory.current_bank()[R1]);
    return 1;
}

///////////////////////////////////////////////////////////////
/// MOV @Ri, A
///////////////////////////////////////////////////////////////

uint8_t __mov_at_r0_a__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.locate(cpu.c51_memory.current_bank()[R0]) = *cpu.c51_memory.acc_A;
    return 1;
}

uint8_t __mov_at_r1_a__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.locate(cpu.c51_memory.current_bank()[R1]) = *cpu.c51_memory.acc_A;
    return 1;
}

///////////////////////////////////////////////////////////////
/// MOV @Ri, direct
///////////////////////////////////////////////////////////////

uint8_t __mov_at_r0_direct__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.locate(cpu.c51_memory.current_bank()[R0]) = *cpu.c51_memory.locate(addr);
    return 2;
}

uint8_t __mov_at_r1_direct__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.locate(cpu.c51_memory.current_bank()[R1]) = *cpu.c51_memory.locate(addr);
    return 2;
}

///////////////////////////////////////////////////////////////
/// MOV direct, @Ri
///////////////////////////////////////////////////////////////

uint8_t __mov_direct_at_r0__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.locate(addr) = *cpu.c51_memory.locate(cpu.c51_memory.current_bank()[R0]);
    return 2;
}

uint8_t __mov_direct_at_r1__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    *cpu.c51_memory.locate(addr) = *cpu.c51_memory.locate(cpu.c51_memory.current_bank()[R1]);
    return 2;
}

///////////////////////////////////////////////////////////////
/// MOV DPTR, #data16
///////////////////////////////////////////////////////////////

uint8_t __mov_dptr_data16__ (c51_cpu & cpu, ...)
{
    uint8_t data1, data2;
    __GET_2_ARGUMENTS__(data1, data2);
    uint16_t dptr = data1 << 8;
    dptr |= data2;
    *cpu.c51_memory.DPTR = dptr;
    return 2;
}

///////////////////////////////////////////////////////////////
/// MOV C, bitaddr
///////////////////////////////////////////////////////////////

uint8_t __mov_c_bitaddr__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    _8bit_set_bit(cpu.c51_memory.prog_stat_wd_PSW, PSW_CY, cpu.c51_memory.bit_access(addr));
    return 1;
}

///////////////////////////////////////////////////////////////
/// MOV bitaddr, C
///////////////////////////////////////////////////////////////

uint8_t __mov_bitaddr_c__ (c51_cpu & cpu, ...)
{
    uint8_t addr;
    __GET_ARGUMENT__(addr);
    cpu.c51_memory.bit_modify(addr, _8bit_get_bit(cpu.c51_memory.prog_stat_wd_PSW, PSW_CY));
    return 1;
}

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
/// MOVC A, @A+DPTR
///////////////////////////////////////////////////////////////

uint8_t __movc_a_at_a_dptr__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.acc_A = cpu.get_code(*cpu.c51_memory.acc_A + *cpu.c51_memory.DPTR);
    return 2;
}

///////////////////////////////////////////////////////////////
/// MOVC A, @A+PC
///////////////////////////////////////////////////////////////

uint8_t __movc_a_at_a_pc__ (c51_cpu & cpu, ...)
{
    *cpu.c51_memory.acc_A = cpu.get_code(*cpu.c51_memory.acc_A + cpu.get_pc());
    return 2;
}

///////////////////////////////////////////////////////////////

uint8_t instruction_arg_count(uint8_t instruction)
{
    switch (instruction)
    {
        case __MOV_R0_DATA__:
        case __MOV_R1_DATA__:
        case __MOV_R2_DATA__:
        case __MOV_R3_DATA__:
        case __MOV_R4_DATA__:
        case __MOV_R5_DATA__:
        case __MOV_R6_DATA__:
        case __MOV_R7_DATA__:

        case __MOV_A_DATA__:

        case __MOV_A_DIRECT__:

        case __MOV_R0_DIRECT__:
        case __MOV_R1_DIRECT__:
        case __MOV_R2_DIRECT__:
        case __MOV_R3_DIRECT__:
        case __MOV_R4_DIRECT__:
        case __MOV_R5_DIRECT__:
        case __MOV_R6_DIRECT__:
        case __MOV_R7_DIRECT__:

        case __MOV_DIRECT_A__:

        case __MOV_DIRECT_R0__:
        case __MOV_DIRECT_R1__:
        case __MOV_DIRECT_R2__:
        case __MOV_DIRECT_R3__:
        case __MOV_DIRECT_R4__:
        case __MOV_DIRECT_R5__:
        case __MOV_DIRECT_R6__:
        case __MOV_DIRECT_R7__:

        case __MOV_AT_R0_DATA__:
        case __MOV_AT_R1_DATA__:

        case __MOV_AT_R0_DIRECT__:
        case __MOV_AT_R1_DIRECT__:

        case __MOV_DIRECT_AT_R0__:
        case __MOV_DIRECT_AT_R1__:

        case __MOV_C_BITADDR__:

        case __MOV_BITADDR_C__:
            return 1;

        case __MOV_DIRECT_DIRECT__:
        case __MOV_DIRECT_DATA__:

        case __MOV_DPTR_DATA16__:
            return 2;

        default:
            return 0;
    }
}

uint64_t c51_cpu::exec(by_exec_t before_exec, by_exec_t after_exec)
{
    uint8_t instruction, args[2];
    ihx_file >> instruction;

    for (uint8_t i = 0; i < instruction_arg_count(instruction); i++)
    {
        ihx_file >> args[i];
    }

    if (before_exec)
    {
        before_exec(instruction, this, args[0], args[1]);
    }

    auto clock_count = instruction_set.at(instruction)(*this, args[0], args[1]);
    cur_time += clock_count;

    for (uint64_t i = 0; i < clock_count; i++)
    {
        clock_invocation();
    }

    if (after_exec)
    {
        after_exec(instruction, this, args[0], args[1]);
    }

    return cur_time;
}

c51_cpu::c51_cpu(const std::string &filename) : ihx_file(filename)
{
    __EMPLACE_OPERATION__(__NOP__, __nop__);

    __EMPLACE_OPERATION__(__MOV_R0_DATA__, __mov_r0_data__);
    __EMPLACE_OPERATION__(__MOV_R1_DATA__, __mov_r1_data__);
    __EMPLACE_OPERATION__(__MOV_R2_DATA__, __mov_r2_data__);
    __EMPLACE_OPERATION__(__MOV_R3_DATA__, __mov_r3_data__);
    __EMPLACE_OPERATION__(__MOV_R4_DATA__, __mov_r4_data__);
    __EMPLACE_OPERATION__(__MOV_R5_DATA__, __mov_r5_data__);
    __EMPLACE_OPERATION__(__MOV_R6_DATA__, __mov_r6_data__);
    __EMPLACE_OPERATION__(__MOV_R7_DATA__, __mov_r7_data__);

    __EMPLACE_OPERATION__(__MOV_A_R0__, __mov_a_r0__);
    __EMPLACE_OPERATION__(__MOV_A_R1__, __mov_a_r1__);
    __EMPLACE_OPERATION__(__MOV_A_R2__, __mov_a_r2__);
    __EMPLACE_OPERATION__(__MOV_A_R3__, __mov_a_r3__);
    __EMPLACE_OPERATION__(__MOV_A_R4__, __mov_a_r4__);
    __EMPLACE_OPERATION__(__MOV_A_R5__, __mov_a_r5__);
    __EMPLACE_OPERATION__(__MOV_A_R6__, __mov_a_r6__);
    __EMPLACE_OPERATION__(__MOV_A_R7__, __mov_a_r7__);

    __EMPLACE_OPERATION__(__MOV_R0_A__, __mov_r0_a__);
    __EMPLACE_OPERATION__(__MOV_R1_A__, __mov_r1_a__);
    __EMPLACE_OPERATION__(__MOV_R2_A__, __mov_r2_a__);
    __EMPLACE_OPERATION__(__MOV_R3_A__, __mov_r3_a__);
    __EMPLACE_OPERATION__(__MOV_R4_A__, __mov_r4_a__);
    __EMPLACE_OPERATION__(__MOV_R5_A__, __mov_r5_a__);
    __EMPLACE_OPERATION__(__MOV_R6_A__, __mov_r6_a__);
    __EMPLACE_OPERATION__(__MOV_R7_A__, __mov_r7_a__);

    __EMPLACE_OPERATION__(__MOV_A_DATA__, __mov_a_data__);

    __EMPLACE_OPERATION__(__MOV_A_DIRECT__, __mov_a_direct__);

    __EMPLACE_OPERATION__(__MOV_R0_DIRECT__, __mov_r0_direct__);
    __EMPLACE_OPERATION__(__MOV_R1_DIRECT__, __mov_r1_direct__);
    __EMPLACE_OPERATION__(__MOV_R2_DIRECT__, __mov_r2_direct__);
    __EMPLACE_OPERATION__(__MOV_R3_DIRECT__, __mov_r3_direct__);
    __EMPLACE_OPERATION__(__MOV_R4_DIRECT__, __mov_r4_direct__);
    __EMPLACE_OPERATION__(__MOV_R5_DIRECT__, __mov_r5_direct__);
    __EMPLACE_OPERATION__(__MOV_R6_DIRECT__, __mov_r6_direct__);
    __EMPLACE_OPERATION__(__MOV_R7_DIRECT__, __mov_r7_direct__);

    __EMPLACE_OPERATION__(__MOV_DIRECT_A__, __mov_direct_a__);

    __EMPLACE_OPERATION__(__MOV_DIRECT_R0__, __mov_direct_r0__);
    __EMPLACE_OPERATION__(__MOV_DIRECT_R1__, __mov_direct_r1__);
    __EMPLACE_OPERATION__(__MOV_DIRECT_R2__, __mov_direct_r2__);
    __EMPLACE_OPERATION__(__MOV_DIRECT_R3__, __mov_direct_r3__);
    __EMPLACE_OPERATION__(__MOV_DIRECT_R4__, __mov_direct_r4__);
    __EMPLACE_OPERATION__(__MOV_DIRECT_R5__, __mov_direct_r5__);
    __EMPLACE_OPERATION__(__MOV_DIRECT_R6__, __mov_direct_r6__);
    __EMPLACE_OPERATION__(__MOV_DIRECT_R7__, __mov_direct_r7__);

    __EMPLACE_OPERATION__(__MOV_DIRECT_DIRECT__, __mov_direct_direct__);

    __EMPLACE_OPERATION__(__MOV_DIRECT_DATA__, __mov_direct_data__);

    __EMPLACE_OPERATION__(__MOV_AT_R0_DATA__, __mov_at_r0_data__);
    __EMPLACE_OPERATION__(__MOV_AT_R1_DATA__, __mov_at_r1_data__);

    __EMPLACE_OPERATION__(__MOV_A_AT_R0__, __mov_a_at_r0__);
    __EMPLACE_OPERATION__(__MOV_A_AT_R1__, __mov_a_at_r1__);

    __EMPLACE_OPERATION__(__MOV_AT_R0_A__, __mov_at_r0_a__);
    __EMPLACE_OPERATION__(__MOV_AT_R1_A__, __mov_at_r1_a__);

    __EMPLACE_OPERATION__(__MOV_AT_R0_DIRECT__, __mov_at_r0_direct__);
    __EMPLACE_OPERATION__(__MOV_AT_R1_DIRECT__, __mov_at_r1_direct__);

    __EMPLACE_OPERATION__(__MOV_DIRECT_AT_R0__, __mov_direct_at_r0__);
    __EMPLACE_OPERATION__(__MOV_DIRECT_AT_R1__, __mov_direct_at_r1__);

    __EMPLACE_OPERATION__(__MOV_DPTR_DATA16__, __mov_dptr_data16__);

    __EMPLACE_OPERATION__(__MOV_C_BITADDR__, __mov_c_bitaddr__);

    __EMPLACE_OPERATION__(__MOV_BITADDR_C__, __mov_bitaddr_c__);

    __EMPLACE_OPERATION__(__MOVC_A_AT_A_DPTR__, __movc_a_at_a_dptr__);

    __EMPLACE_OPERATION__(__MOVC_A_AT_A_PC__, __movc_a_at_a_pc__);
}

void c51_cpu::clock_invocation()
{

}
