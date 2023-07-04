#include "sexy_primes.hpp"

#include <gtest/gtest.h>

TEST(task5_tests, sexy_prime_test)
{
    const auto limit = 20U;
    const auto expectedResult =
        SexyPrimes({ { 5, 11 }, { 7, 13 }, { 11, 17 }, { 13, 19 } });

    const auto result = getAllSexyPrimesUptoLimit(limit);

    EXPECT_EQ(result.size(), expectedResult.size());

    for (auto i = 0U; i < result.size(); i++) {
        EXPECT_EQ(result[i], expectedResult[i]);
    }
}