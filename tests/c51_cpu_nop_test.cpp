#include <cpu.h>
#include <debug.h>
#include <cstring>

/** @file
 *
 * This file defines test for C51 CPU instruction set NOP
 */


int main(int argc, char ** argv)
{
    try
    {
        c51_cpu CPU(PROJECT_BINARY_DIR "/ihx_output/nop.ihx");
        CPU.exec();
    }
    catch (std::exception & err)
    {
        std::cout << err.what() << std::endl;
        return EXIT_FAILURE;
    }
}
