#include "ints_to_hex_repr.h"

#include <gtest/gtest.h>

TEST(ints_to_hex_test, conversion)
{
    const std::vector<int> input{
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
    };

    const std::string expected = "000102030405060708090A0B0C0D0E0F";
    EXPECT_EQ(ints_to_hex(input), expected);
}

TEST(ints_to_hex_test, conversion_to_lower)
{
    const std::vector<int> input{
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
    };

    const std::string expected = "000102030405060708090a0b0c0d0e0f";
    EXPECT_EQ(ints_to_hex(input, false), expected);
}