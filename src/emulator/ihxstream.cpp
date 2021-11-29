#include <ihxstream.h>
#include <emu_error.h>
#include <memory>
#include <debug.h>

#define IHX_START_CODE ':'

ihxstream::ihxstream(const std::string &filename)
{
    file.open(filename);

    if (!file)
    {
        throw emu_error_t(C51_EMU_IHXSTREAMN_ABORT);
    }

    for (std::map < uint16_t, std::vector < uint8_t > > line = readline();
        !line.empty(); line = readline())
    {
        program.emplace(line.begin()->first, line.begin()->second);
    }

    file.close();

    fill_64bit_program_stack();
}

std::map < uint16_t, std::vector < uint8_t > > ihxstream::readline()
{
    std::vector < char >    lit_data;
    std::vector < uint8_t > data;
    char starting_code = 0,
         lit_byte_count [3]{},
         lit_address    [5]{},
         lit_record_type[3]{},
         lit_checksum   [3]{};
    uint8_t     byte_count;
    uint16_t    address;
    uint8_t     address_split[2];
    uint8_t     record_type;
    uint8_t     checksum;

    // read first 4 sections

    while (starting_code != IHX_START_CODE)
    {
        if (!file)
        {
            return {}; // EOF
        }

        file >> starting_code;
    }

    file.read(lit_byte_count, 2);
    file.read(lit_address, 4);
    file.read(lit_record_type, 2);

    // convert lit to num
    byte_count = strtol(lit_byte_count, nullptr, 16);
    address = strtol(lit_address, nullptr, 16);
    record_type = strtol(lit_record_type, nullptr, 16);

    address_split[0] = address;
    address_split[1] = address >> 8;

    // read data
    for (uint64_t i = 0; i < byte_count * 2; i++)
    {
        char tmp;
        file.read(&tmp, 1);
        lit_data.push_back(tmp);
    }

    for (uint64_t i = 0; i < lit_data.size(); i += 2)
    {
        char tmp[3] {};
        tmp[0] = lit_data[i];
        tmp[1] = lit_data[i + 1];

        data.push_back(strtol(tmp, nullptr, 16));
    }

    // read checksum
    file.read(lit_checksum, 2);
    checksum = strtol(lit_checksum, nullptr, 16);

    // check EOF
    if (record_type == 0x01)
    {
        return {};
    }

    // verify

    uint8_t cmp_of_checksum = byte_count + address_split[0] + address_split[1] + record_type;
    for (auto i : data)
    {
        cmp_of_checksum += i;
    }

#ifdef __ENABLE_IHX_CHECKSUM__
    if ((uint8_t)checksum != (uint8_t)(~cmp_of_checksum))
    {
        throw emu_error_t(C51_EMU_IHX_FILE_CORRUPT);
    }
#endif // __ENABLE_IHX_CHECKSUM__

    // return result
    std::map < uint16_t, std::vector < uint8_t > > ret;
    ret.emplace(address, data);
    return ret;
}

void ihxstream::fill_64bit_program_stack()
{
    for (auto line : program)
    {
        for (uint64_t i = 0; i < line.second.size(); i++)
        {
            (_64bit_program_stack + line.first)[i] = line.second[i];
        }
    }
}

uint16_t ihxstream::get_pc() const
{
    return read_offset;
}
