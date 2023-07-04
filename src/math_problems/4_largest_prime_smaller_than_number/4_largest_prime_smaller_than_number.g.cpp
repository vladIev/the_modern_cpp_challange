#include "largest_prime.hpp"

#include <gtest/gtest.h>

TEST(task4_tests, largest_prime_test)
{
    EXPECT_EQ(getLargestPrime(2), 1);
    EXPECT_EQ(getLargestPrime(3), 2);
    EXPECT_EQ(getLargestPrime(5), 3);
    EXPECT_EQ(getLargestPrime(8), 7);
    EXPECT_EQ(getLargestPrime(12), 11);
    EXPECT_EQ(getLargestPrime(16), 13);
    EXPECT_EQ(getLargestPrime(18), 17);
}