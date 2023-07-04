#include "math_utils.h"

#include <gtest/gtest.h>

TEST(task3_tests, lcm_test)
{
    EXPECT_EQ(utils::math::lcm(4, 5), 20);
    EXPECT_EQ(utils::math::lcm(17, 19), 17 * 19);
}