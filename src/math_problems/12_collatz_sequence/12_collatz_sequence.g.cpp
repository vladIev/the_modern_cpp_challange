#include "collatz_sequence.hpp"

#include <gtest/gtest.h>

TEST(collatz, longest)
{
    const uint32_t expectedNumber = 837799;
    const uint32_t expectedLength = 524;
    const auto result = longestCollatz(1'000'000);
    EXPECT_EQ(expectedNumber, result.first);
    EXPECT_EQ(expectedLength, 524);
}