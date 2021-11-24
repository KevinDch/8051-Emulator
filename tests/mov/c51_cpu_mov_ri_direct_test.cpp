#include <cpu.h>
#include <debug.h>
#include <cstring>
#include <cstdlib>

/** @file
 *
 * This file defines test for C51 CPU instruction set MOV Ri, direct
 */

void check_val(uint8_t instruction, c51_cpu* CPU, ...)
{
    switch (instruction)
    {
        case __MOV_AT_R0_DIRECT__:
            if (*CPU->c51_memory.locate(0x16) != 0x18)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOV_AT_R1_DIRECT__:
            if (*CPU->c51_memory.locate(0x17) != 0x19)
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
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/mov_ri_direct.ihx");
        //////////////////////////////////////////////////////////////////
        CPU.exec();
        CPU.exec();
        CPU.exec();
        CPU.exec();

        CPU.exec(nullptr, check_val);
        CPU.exec(nullptr, check_val);
    }
    catch (std::exception & err)
    {
        std::cout << err.what() << " (errno=" << strerror(errno) << ")" << std::endl;
        return EXIT_FAILURE;
    }
}
