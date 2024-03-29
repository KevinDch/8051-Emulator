#ifndef C51_EMU_IHXSTREAM_H
#define C51_EMU_IHXSTREAM_H

/** @file
 *
 * This file defines operations for IHX stream support
 */

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cstdint>

class ihxstream
{
private:
    std::ifstream file;
    std::map < uint16_t, std::vector < uint8_t > > program;
    uint8_t _64bit_program_stack [1024 * 64] { };

    uint16_t read_offset = 0;

    /// read a single line of IHX file
    /// @return data of that line, converted, with address attached
    std::map < uint16_t, std::vector < uint8_t > > readline();

    /// fill _64bit_program_stack using data collected in program
    void fill_64bit_program_stack();

public:
    /// convert ihx file into std::map < uint16_t, std::vector < uint8_t > >
    /// for further operation
    /// @param filename path to file
    explicit ihxstream(const std::string & filename);

    /// @return return next char in data pool, offset recorded
    uint8_t next()
        {
            return _64bit_program_stack[read_offset++];
        }

    /// same as next, but in stream mode
    ihxstream & operator >>(uint8_t& ret) { ret = next(); return *this; }

    /// reset read offset
    /// @param new_offset new offset
    void reset(uint16_t new_offset = 0)
        {   read_offset = new_offset;   }

    /// get code memory
    [[nodiscard]] uint8_t get_code(uint16_t addr) const { return _64bit_program_stack[addr]; }

    /// get program counter
    [[nodiscard]] uint16_t get_pc() const;
};

#endif //C51_EMU_IHXSTREAM_H
