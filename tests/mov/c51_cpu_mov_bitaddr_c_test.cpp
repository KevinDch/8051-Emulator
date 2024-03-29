#include <cpu.h>
#include <debug.h>
#include <cstring>
#include <cstdlib>

/** @file
 *
 * This file defines test for C51 CPU instruction set MOV C, bitaddr
 */

void check_val(uint8_t, c51_cpu* CPU, ...)
{
    if (!CPU->c51_memory.bit_access(0x00))
    {
        exit(EXIT_FAILURE);
    }
}


int main(int argc, char ** argv)
{
    try
    {
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/mov_bitaddr_c.ihx");

        _8bit_set_bit(CPU.c51_memory.prog_stat_wd_PSW, PSW_CY, true);
        //////////////////////////////////////////////////////////////////
        CPU.exec(nullptr, check_val);
    }
    catch (std::exception & err)
    {
        std::cout << err.what() << " (errno=" << strerror(errno) << ")" << std::endl;
        return EXIT_FAILURE;
    }
}
