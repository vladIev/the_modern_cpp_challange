#include "numbers_to_roman.hpp"

#include <gtest/gtest.h>
#include <string_view>

using namespace std::literals;

TEST(to_romans, breathing)
{

    const std::vector<std::pair<int, std::string_view>> testData{
        { 1, "I"sv },
        { 3, "III"sv },
        { 4, "IV"sv },
        { 5, "V"sv },
        { 6, "VI"sv },
        { 9, "IX"sv },
        { 10, "X"sv },
        { 11, "XI"sv },
        { 40, "XL"sv },
        { 50, "L"sv },
        { 90, "XC"sv },
        { 100, "C"sv },
        { 400, "CD"sv },
        { 500, "D"sv },
        { 900, "CM"sv },
        { 1000, "M"sv },
        { 1999, "MCMXCIX"sv },
        { 1452, "MCDLII"sv },
    };

    for (const auto &[value, expected] : testData) {
        EXPECT_EQ(toRoman(value), expected);
    }
}