#include <emu_error.h>
#include <iostream>

/** @file
 *
 * This file defines test for error class
 */


int main()
{
    try {
        throw emu_error_t(0);
    }
    catch (std::exception & err)
    {
        std::cout << err.what() << std::endl;
        return 0;
    }
}
