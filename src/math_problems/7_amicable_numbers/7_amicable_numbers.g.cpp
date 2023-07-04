#include "amicable_numbers.hpp"
#include <gtest/gtest.h>


TEST(task7_tests, amicables_numbers_up_to_limit)
{
    const auto limit = 1300;
    const amicable_pairs expectedResult{
        { 220, 284 },
        { 1184, 1210 },
    };
    const auto actualResult = getAmicablesNumberUptoLimit(limit);
    EXPECT_EQ(actualResult.size(), expectedResult.size());
    EXPECT_EQ(actualResult, expectedResult);
}
