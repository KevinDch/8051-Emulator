#include <cpu.h>
#include <debug.h>
#include <cstring>
#include <cstdlib>

/** @file
 *
 * This file defines test for C51 CPU instruction set MOV Rn, #data
 */


int main(int argc, char ** argv)
{
    try
    {
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/mov_rn_data.ihx");
        CPU.exec();
        if (CPU.c51_memory.current_bank()[R0] != 0x16)
        {
            return EXIT_FAILURE;
        }

        CPU.exec();
        if (CPU.c51_memory.current_bank()[R1] != 0x17)
        {
            return EXIT_FAILURE;
        }

        CPU.exec();
        if (CPU.c51_memory.current_bank()[R2] != 0x18)
        {
            return EXIT_FAILURE;
        }

        CPU.exec();
        if (CPU.c51_memory.current_bank()[R3] != 0x19)
        {
            return EXIT_FAILURE;
        }

        CPU.exec();
        if (CPU.c51_memory.current_bank()[R4] != 0x1A)
        {
            return EXIT_FAILURE;
        }

        CPU.exec();
        if (CPU.c51_memory.current_bank()[R5] != 0x1B)
        {
            return EXIT_FAILURE;
        }

        CPU.exec();
        if (CPU.c51_memory.current_bank()[R6] != 0x1C)
        {
            return EXIT_FAILURE;
        }

        CPU.exec();
        if (CPU.c51_memory.current_bank()[R7] != 0x1D)
        {
            return EXIT_FAILURE;
        }
    }
    catch (std::exception & err)
    {
        std::cout << err.what() << " (errno=" << strerror(errno) << ")" << std::endl;
        return EXIT_FAILURE;
    }
}
