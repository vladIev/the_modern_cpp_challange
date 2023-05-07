#include "task1.h"

#include <limits>

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(task1_tests, happy_path)
{
    EXPECT_EQ(calculateSum(42), 408);
    EXPECT_EQ(calculateSum(0), 0);
}

TEST(task1_tests, no_overflow)
{
    const auto max = std::numeric_limits<uint32_t>::max();
    EXPECT_LT(max, calculateSum(max));
}