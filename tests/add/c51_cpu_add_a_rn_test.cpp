#include <cpu.h>
#include <debug.h>
#include <cstring>
#include <cstdlib>

/** @file
 *
 * This file defines test for C51 CPU instruction set ADD A, Rn
 */

void check_val(uint8_t instruction, c51_cpu* CPU, ...)
{
    switch (instruction) {
        case __ADD_A_R0__:
            if (*CPU->c51_memory.acc_A != 0x90)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __ADD_A_R1__:
            if (*CPU->c51_memory.acc_A != 0x91)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __ADD_A_R2__:
            if (*CPU->c51_memory.acc_A != 0x92)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __ADD_A_R3__:
            if (*CPU->c51_memory.acc_A != 0x93)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __ADD_A_R4__:
            if (*CPU->c51_memory.acc_A != 0x94)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __ADD_A_R5__:
            if (*CPU->c51_memory.acc_A != 0x95)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __ADD_A_R6__:
            if (*CPU->c51_memory.acc_A != 0x96)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __ADD_A_R7__:
            if (*CPU->c51_memory.acc_A != 0x97)
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
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/add_a_rn.ihx");
        //////////////////////////////////////////////////////////////////
        CPU.exec();
        CPU.exec();
        CPU.exec();
        CPU.exec();
        CPU.exec();
        CPU.exec();
        CPU.exec();
        CPU.exec();

        CPU.exec(nullptr, check_val);
        CPU.exec();

        CPU.exec(nullptr, check_val);
        CPU.exec();

        CPU.exec(nullptr, check_val);
        CPU.exec();

        CPU.exec(nullptr, check_val);
        CPU.exec();

        CPU.exec(nullptr, check_val);
        CPU.exec();

        CPU.exec(nullptr, check_val);
        CPU.exec();

        CPU.exec(nullptr, check_val);
        CPU.exec();

        CPU.exec(nullptr, check_val);
    }
    catch (std::exception & err)
    {
        std::cout << err.what() << " (errno=" << strerror(errno) << ")" << std::endl;
        return EXIT_FAILURE;
    }
}
