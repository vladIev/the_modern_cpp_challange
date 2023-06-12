#include "prime_factors.hpp"

#include <gtest/gtest.h>

TEST(prime_factors, breathing)
{
    {
        const std::vector<uint64_t> expected{ 2, 2, 2 };
        const auto factors = primeFactors(8);
        EXPECT_EQ(factors, expected);
    }

    {
        const std::vector<uint64_t> expected{ 2, 3, 7 };
        const auto factors = primeFactors(42);
        EXPECT_EQ(factors, expected);
    }

    {
        const std::vector<uint64_t> expected{ 17, 19, 23 };
        const auto factors = primeFactors(7429);
        EXPECT_EQ(factors, expected);
    }
}