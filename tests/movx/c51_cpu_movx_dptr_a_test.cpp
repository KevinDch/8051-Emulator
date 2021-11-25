#include <cpu.h>
#include <debug.h>
#include <cstring>
#include <cstdlib>

/** @file
 *
 * This file defines test for C51 CPU instruction set MOVC A, @A+DPTR
 */

void check_val(uint8_t, c51_cpu* CPU, ...)
{
    if (*CPU->c51_memory.locatex(0x01) != 0x01)
    {
        exit(EXIT_FAILURE);
    }
}


int main(int argc, char ** argv)
{
    try
    {
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/movx_dptr_a.ihx");
        //////////////////////////////////////////////////////////////////
        CPU.exec();
        CPU.exec();

        CPU.exec(nullptr, check_val);
    }
    catch (std::exception & err)
    {
        std::cout << err.what() << " (errno=" << strerror(errno) << ")" << std::endl;
        return EXIT_FAILURE;
    }
}
