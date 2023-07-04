#include "math_utils.h"

#include <bitset>
#include <vector>
#include <tuple>

auto toBitRepresentation(uint8_t value, uint8_t numOfBits) -> std::string
{
    return std::bitset<8>(value).to_string().substr(8 - numOfBits, numOfBits);
}

auto grayEncode(uint8_t value) -> uint8_t { return value ^ (value >> 1); }

auto grayDecode(uint8_t value) -> uint8_t
{
    for (uint8_t bit = 1U << 7; bit > 1; bit >>= 1) {
        if (value & bit) { value ^= bit >> 1; }
    }
    return value;
}

auto solution(uint8_t numOfBits)
    -> std::vector<std::tuple<std::string, uint8_t, uint8_t>>
{
    const auto limit = static_cast<uint8_t>(std::pow(2U, numOfBits));
    std::vector<std::tuple<std::string, uint8_t, uint8_t>> result;

    for (uint8_t i = 0; i < limit; i++) {
        const auto binary = toBitRepresentation(i, numOfBits);
        const auto grayEncoded = grayEncode(i);
        const auto grayDecoded = grayDecode(grayEncoded);

        result.emplace_back(binary, grayEncoded, grayDecoded);
    }
    return result;
}