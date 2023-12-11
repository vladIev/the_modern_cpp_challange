#include "parallel_minmax.hpp"

#include <algorithm>
#include <gtest/gtest.h>
#include <numeric>
#include <random>

auto prepareTestData(int min, int max) -> std::vector<int>
{
    EXPECT_LT(min, max);
    std::vector<int> testData(max - min + 1);
    std::iota(testData.begin(), testData.end(), min);
    std::random_device rd;
    std::mt19937 gen(42);

    std::shuffle(testData.begin(), testData.end(), gen);
    return testData;
}

TEST(parallel_min_and_max, min_test)
{
    const auto testData = prepareTestData(-500, 500);
    auto result = pmin(testData.begin(), testData.end());
    EXPECT_EQ(result, -500);
}

TEST(parallel_min_and_max, max_test)
{
    const auto testData = prepareTestData(-500, 500);
    auto result = pmax(testData.begin(), testData.end());
    EXPECT_EQ(result, 500);
}