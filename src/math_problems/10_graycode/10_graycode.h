#include "math_utils.h"

#include <bitset>
#include <vector>
#include <tuple>

auto to_bit_representation(uint8_t value, uint8_t num_of_bits) -> std::string
{
    return std::bitset<8>(value).to_string().substr(
        8 - num_of_bits, num_of_bits);
}

auto gray_encode(uint8_t value) -> uint8_t { return value ^ (value >> 1); }

auto gray_decode(uint8_t value) -> uint8_t
{
    for (uint8_t bit = 1u << 7; bit > 1; bit >>= 1) {
        if (value & bit) { value ^= bit >> 1; }
    }
    return value;
}

auto solution(uint8_t num_of_bits)
    -> std::vector<std::tuple<std::string, uint8_t, uint8_t>>
{
    const uint8_t limit = static_cast<uint8_t>(std::pow(2u, num_of_bits));
    std::vector<std::tuple<std::string, uint8_t, uint8_t>> result;

    for (uint8_t i = 0; i < limit; i++) {
        const auto binary = to_bit_representation(i, num_of_bits);
        const auto gray_encoded = gray_encode(i);
        const auto gray_decoded = gray_decode(gray_encoded);

        result.push_back({ binary, gray_encoded, gray_decoded });
    }
    return result;
}