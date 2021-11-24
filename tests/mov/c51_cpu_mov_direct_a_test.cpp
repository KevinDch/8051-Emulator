#include <cpu.h>
#include <debug.h>
#include <cstring>
#include <cstdlib>

/** @file
 *
 * This file defines test for C51 CPU instruction set MOV direct, A
 */

void check_val(uint8_t, c51_cpu* CPU, ...)
{
    if (*CPU->c51_memory.locate(0x16) != 0x16)
    {
        exit(EXIT_FAILURE);
    }
}


int main(int argc, char ** argv)
{
    try
    {
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/mov_direct_a.ihx");
        //////////////////////////////////////////////////////////////////
        *CPU.c51_memory.acc_A = 0x16;
        CPU.exec(nullptr, check_val);
    }
    catch (std::exception & err)
    {
        std::cout << err.what() << " (errno=" << strerror(errno) << ")" << std::endl;
        return EXIT_FAILURE;
    }
}
