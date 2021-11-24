#include <c51_memory.h>

void _8bit_set_bit(uint8_t * addr, int bit_pos, bool bit)
{
    if (bit)
    {
        uint8_t data = 1 << bit_pos;
        *addr |= data;
    }
    else
    {
        uint8_t data = 1 << bit_pos;
        data = ~data;
        *addr &= data;
    }
}

bool _8bit_get_bit(const uint8_t * addr, int bit_pos)
{
    uint8_t data = *addr;
    data >>= bit_pos;
    data &= 0x01;
    return data;
}

uint8_t *memory::current_bank() const
{
    if (_8bit_get_bit(prog_stat_wd_PSW, PSW_RS0) == 0)
    {
        if (_8bit_get_bit(prog_stat_wd_PSW, PSW_RS1) == 0)
        {
            return register_bank_0;
        }
        else
        {
            return register_bank_1;
        }
    }
    else
    {
        if (_8bit_get_bit(prog_stat_wd_PSW, PSW_RS1) == 0)
        {
            return register_bank_2;
        }
        else
        {
            return register_bank_3;
        }
    }
}

bool memory::bit_access(uint8_t bit_addr)
{
    uint8_t * bit_starting_addr = locate(0x20);
    uint8_t byte_location = bit_addr / 8 + (bit_addr % 8 == 0 ? 0 : 1);
    uint8_t bit_location = bit_addr % 8;

    uint8_t byte = bit_starting_addr[byte_location];
    byte >>= bit_location;
    return byte & 0x01;
}

void memory::bit_modify(uint8_t bit_addr, bool val)
{
    uint8_t * bit_starting_addr = locate(0x20);
    uint8_t byte_location = bit_addr / 8 + (bit_addr % 8 == 0 ? 0 : 1);
    uint8_t bit_location = bit_addr % 8;

    if (val)
    {
        uint8_t byte = 0x01 << bit_location;
        bit_starting_addr[byte_location] |= byte;
    }
    else
    {
        uint8_t byte = 0x01 << bit_location;
        byte = ~byte;
        bit_starting_addr[byte_location] &= byte;
    }
}
