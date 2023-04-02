#include <gtest/gtest.h>
#include "math_utils.hpp"

TEST(task2_tests, gcd_test)
{
    EXPECT_EQ(utils::math::gcd(35, 40), 5);
    EXPECT_EQ(utils::math::gcd(17, 19), 1);
}