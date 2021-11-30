#include <cpu.h>
#include <debug.h>
#include <cstring>
#include <cstdlib>

/** @file
 *
 * This file defines test for C51 CPU instruction set INC Rn
 */

void check_val(uint8_t instruction, c51_cpu* CPU, ...)
{
    switch (instruction)
    {
        case __INC_R0__:
            if (CPU->c51_memory.current_bank()[R0] != 0x01)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __INC_R1__:
            if (CPU->c51_memory.current_bank()[R1] != 0x01)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __INC_R2__:
            if (CPU->c51_memory.current_bank()[R2] != 0x01)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __INC_R3__:
            if (CPU->c51_memory.current_bank()[R3] != 0x01)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __INC_R4__:
            if (CPU->c51_memory.current_bank()[R4] != 0x01)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __INC_R5__:
            if (CPU->c51_memory.current_bank()[R5] != 0x01)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __INC_R6__:
            if (CPU->c51_memory.current_bank()[R6] != 0x01)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __INC_R7__:
            if (CPU->c51_memory.current_bank()[R7] != 0x01)
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
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/inc_rn.ihx");
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
