#include <cpu.h>
#include <debug.h>
#include <cstring>
#include <cstdlib>

/** @file
 *
 * This file defines test for C51 CPU instruction set MOV direct, direct
 */

void check_val(uint8_t, c51_cpu* CPU, ...)
{
    if (*CPU->c51_memory.locate(0x16) != 0x17)
    {
        exit(EXIT_FAILURE);
    }
}


int main(int argc, char ** argv)
{
    try
    {
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/mov_direct_direct.ihx");
        //////////////////////////////////////////////////////////////////
        *CPU.c51_memory.locate(0x17) = 0x17;
        CPU.exec(nullptr, check_val);
        CPU.exec(nullptr);
    }
    catch (std::exception & err)
    {
        std::cout << err.what() << " (errno=" << strerror(errno) << ")" << std::endl;
        return EXIT_FAILURE;
    }
}
