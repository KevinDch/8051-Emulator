#include <cpu.h>
#include <debug.h>
#include <cstring>
#include <cstdlib>

/** @file
 *
 * This file defines test for C51 CPU instruction set MOV A, Rn
 */

void check_val(uint8_t instruction, c51_cpu* CPU, ...)
{
    switch (instruction) {
        case __MOV_A_R0__:
            if (*CPU->c51_memory.acc_A != 0x16)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_A_R1__:
            if (*CPU->c51_memory.acc_A != 0x17)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_A_R2__:
            if (*CPU->c51_memory.acc_A != 0x18)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_A_R3__:
            if (*CPU->c51_memory.acc_A != 0x19)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_A_R4__:
            if (*CPU->c51_memory.acc_A != 0x1A)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_A_R5__:
            if (*CPU->c51_memory.acc_A != 0x1B)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_A_R6__:
            if (*CPU->c51_memory.acc_A != 0x1C)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_A_R7__:
            if (*CPU->c51_memory.acc_A != 0x1D)
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
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/mov_a_rn.ihx");
        for (uint64_t i = 0; i < 8; i++)
        {
            CPU.exec();
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
