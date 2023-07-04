#include "abundant_numbers.hpp"
#include "math_utils.h"

#include <gtest/gtest.h>

TEST(task6_tests, sum_of_proper_divisors)
{
    EXPECT_EQ(utils::math::get_sum_of_divisors(12), 16);
    EXPECT_EQ(utils::math::get_sum_of_divisors(5), 1);
}

TEST(task6_tests, is_abundant)
{
    const auto divisorsSum12 = utils::math::get_sum_of_divisors(12);
    const auto divisorsSum17 = utils::math::get_sum_of_divisors(17);
    EXPECT_TRUE(isAbundant(12, divisorsSum12));
    EXPECT_FALSE(isAbundant(17, divisorsSum17));
}

TEST(task6_tests, abundand_numbers_up_to_limit)
{
    const auto limit = 30;
    const std::vector<abundant_and_abundance> expectedResult{
        { 12, 4 }, { 18, 3 }, { 20, 2 }, { 24, 12 }
    };
    const auto actual_result = getAbundantsNumberUptoLimit(limit);
    EXPECT_EQ(actual_result.size(), expectedResult.size());
    EXPECT_EQ(actual_result, expectedResult);
}
