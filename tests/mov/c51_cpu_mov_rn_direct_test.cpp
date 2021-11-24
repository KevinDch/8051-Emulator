#include <cpu.h>
#include <debug.h>
#include <cstring>
#include <cstdlib>

/** @file
 *
 * This file defines test for C51 CPU instruction set MOV Rn, direct
 */


void check_val(uint8_t instruction, c51_cpu* CPU, ...)
{
    switch (instruction)
    {
        case __MOV_R0_DIRECT__:
            if (CPU->c51_memory.current_bank()[R0] != 0x16)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R1_DIRECT__:
            if (CPU->c51_memory.current_bank()[R1] != 0x17)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R2_DIRECT__:
            if (CPU->c51_memory.current_bank()[R2] != 0x18)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R3_DIRECT__:
            if (CPU->c51_memory.current_bank()[R3] != 0x19)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R4_DIRECT__:
            if (CPU->c51_memory.current_bank()[R4] != 0x1A)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R5_DIRECT__:
            if (CPU->c51_memory.current_bank()[R5] != 0x1B)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R6_DIRECT__:
            if (CPU->c51_memory.current_bank()[R6] != 0x1C)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R7_DIRECT__:
            if (CPU->c51_memory.current_bank()[R7] != 0x1D)
            {
                exit(EXIT_FAILURE);
            }
            break;

        default:
            exit(EXIT_FAILURE);;
    }
}


int main(int argc, char ** argv)
{
    try
    {
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/mov_rn_direct.ihx");
        for (uint64_t i = 0; i < 8; i++)
        {
            *CPU.c51_memory.locate(0x16 + i) = i + 0x16;
        }

        //////////////////////////////////////////////////////////////////

        CPU.exec(nullptr, check_val);
        CPU.exec(nullptr, check_val);
        CPU.exec(nullptr, check_val);
        CPU.exec(nullptr, check_val);
        CPU.exec(nullptr, check_val);
        CPU.exec(nullptr, check_val);
        CPU.exec(nullptr, check_val);
        CPU.exec(nullptr, check_val);
    }
    catch (std::exception & err)
    {
        std::cout << err.what() << " (errno=" << strerror(errno) << ")" << std::endl;
        return EXIT_FAILURE;
    }
}
