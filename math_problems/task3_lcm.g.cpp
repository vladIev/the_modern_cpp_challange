#include <gtest/gtest.h>
#include "math_utils.hpp"

TEST(task3_tests, lcm_test)
{
    EXPECT_EQ(utils::math::lcm(4, 5), 20);
    EXPECT_EQ(utils::math::lcm(17, 19), 17 * 19);
}