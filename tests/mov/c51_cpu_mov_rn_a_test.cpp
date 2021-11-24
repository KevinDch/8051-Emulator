#include <cpu.h>
#include <debug.h>
#include <cstring>
#include <cstdlib>

/** @file
 *
 * This file defines test for C51 CPU instruction set MOV Rn, A
 */

void check_val(uint8_t instruction, c51_cpu* CPU, ...)
{
    switch (instruction)
    {
        case __MOV_R0_A__:
            if (CPU->c51_memory.current_bank()[R0] != 0x16)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R1_A__:
            if (CPU->c51_memory.current_bank()[R1] != 0x16)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R2_A__:
            if (CPU->c51_memory.current_bank()[R2] != 0x16)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R3_A__:
            if (CPU->c51_memory.current_bank()[R3] != 0x16)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R4_A__:
            if (CPU->c51_memory.current_bank()[R4] != 0x16)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R5_A__:
            if (CPU->c51_memory.current_bank()[R5] != 0x16)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R6_A__:
            if (CPU->c51_memory.current_bank()[R6] != 0x16)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_R7_A__:
            if (CPU->c51_memory.current_bank()[R7] != 0x16)
            {
                exit(EXIT_FAILURE);
            }
            break;

        default:
            exit(EXIT_FAILURE);
    }
}


int main(int argc, char ** argv)
{
    try
    {
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/mov_rn_a.ihx");
        CPU.exec();

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
