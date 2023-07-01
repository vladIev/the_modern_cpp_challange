#include "amicable_numbers.hpp"
#include <gtest/gtest.h>


TEST(task7_tests, amicables_numbers_up_to_limit)
{
    const auto limit = 1300;
    const amicable_pairs expected_result{
        { 220, 284 },
        { 1184, 1210 },
    };
    const auto actual_result = get_amicables_number_upto_limit(limit);
    EXPECT_EQ(actual_result.size(), expected_result.size());
    EXPECT_EQ(actual_result, expected_result);
}
