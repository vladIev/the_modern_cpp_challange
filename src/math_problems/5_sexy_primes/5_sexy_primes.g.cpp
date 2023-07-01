#include "sexy_primes.hpp"

#include <gtest/gtest.h>

TEST(task5_tests, sexy_prime_test)
{
    constexpr auto limit = 20u;
    const auto expected_result =
        sexy_primes({ { 5, 11 }, { 7, 13 }, { 11, 17 }, { 13, 19 } });
    const auto result = get_all_sexy_primes_upto_limit(limit);
    EXPECT_EQ(result.size(), expected_result.size());
    for (auto i = 0u; i < result.size(); i++) {
        EXPECT_EQ(result[i], expected_result[i]);
    }
}