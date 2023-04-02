#include "task6_abundant_numbers.h"

#include <gtest/gtest.h>

TEST(task6_tests, sum_of_proper_divisors)
{
    EXPECT_EQ(get_sum_of_divisors(12), 16);
    EXPECT_EQ(get_sum_of_divisors(5), 1);
}

TEST(task6_tests, is_abundant)
{
    const auto divisors_sum_12 = get_sum_of_divisors(12);
    const auto divisors_sum_17 = get_sum_of_divisors(17);
    EXPECT_TRUE(is_abundant(12, divisors_sum_12));
    EXPECT_FALSE(is_abundant(17, divisors_sum_17));
}

TEST(task6_tests, abundand_numbers_up_to_limit)
{
    const auto limit = 30;
    const std::vector<abundant_and_abundance> expected_result{
        { 12, 4 }, { 18, 3 }, { 20, 2 }, { 24, 12 }
    };
    const auto actual_result = get_abundants_number_upto_limit(limit);
    EXPECT_EQ(actual_result.size(), expected_result.size());
    EXPECT_EQ(actual_result, expected_result);
}
