#include <ihxstream.h>
#include <debug.h>
#include <cstring>

/** @file
 *
 * This file defines test for error class
 */


int main(int argc, char ** argv)
{
    try
    {
        uint8_t data[3]{}, cmp_data[3]{};
        ihxstream ihx_stream(PROJECT_BINARY_DIR "/ihx_output/nop.ihx");
        ihx_stream >> data[0] >> data[1] >> data[2];
        return !!memcmp(data, cmp_data, 3);
    }
    catch (std::exception & err)
    {
        std::cout << err.what() << std::endl;
        return 0;
    }
}
