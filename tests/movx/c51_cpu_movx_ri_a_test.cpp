#include <cpu.h>
#include <debug.h>
#include <cstring>
#include <cstdlib>

/** @file
 *
 * This file defines test for C51 CPU instruction set MOVC @Ri, A
 */

void check_val(uint8_t instruction, c51_cpu* CPU, ...)
{
    switch (instruction) {
        case __MOVX_AT_R0_A__:
            if (*CPU->c51_memory.locatex(0x16) != 0x01)
            {
                exit(EXIT_FAILURE);
            }
            break;

        case __MOVX_AT_R1_A__:
            if (*CPU->c51_memory.locatex(0x17) != 0x01)
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
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/movx_ri_a.ihx");
        //////////////////////////////////////////////////////////////////
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
