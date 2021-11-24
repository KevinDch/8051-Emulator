#include <cpu.h>
#include <debug.h>
#include <cstring>
#include <cstdlib>

/** @file
 *
 * This file defines test for C51 CPU instruction set MOV direct, Rn
 */


void check_val(uint8_t instruction, c51_cpu* CPU, ...)
{
    if (*CPU->c51_memory.DPTR != 0x1234)
    {
        exit(EXIT_FAILURE);
    }
}


int main(int argc, char ** argv)
{
    try
    {
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/mov_dptr_data16.ihx");
        //////////////////////////////////////////////////////////////////
        CPU.exec(nullptr, check_val);
    }
    catch (std::exception & err)
    {
        std::cout << err.what() << " (errno=" << strerror(errno) << ")" << std::endl;
        return EXIT_FAILURE;
    }
}
