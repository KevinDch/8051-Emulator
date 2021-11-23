/** @file
 *
 * This file implements error class and relevant operations
 */

#include <emu_error.h>

const char *emu_error_t::what() const noexcept
{
    switch (error_code)
    {
        case C51_EMU_IHXSTREAMN_ABORT:
            return "IHX stream aborted";

        case C51_EMU_IHX_FILE_CORRUPT:
            return "IHX file corrupted";

        default:
            return C51_EMU_PREFIX "Unknown";
    }
}
