#include "4_largest_prime_smaller_than_number.h"

#include <gtest/gtest.h>

TEST(task4_tests, largest_prime_test)
{
    EXPECT_EQ(get_largest_prime(2), 1);
    EXPECT_EQ(get_largest_prime(3), 2);
    EXPECT_EQ(get_largest_prime(5), 3);
    EXPECT_EQ(get_largest_prime(8), 7);
    EXPECT_EQ(get_largest_prime(12), 11);
    EXPECT_EQ(get_largest_prime(16), 13);
    EXPECT_EQ(get_largest_prime(18), 17);
}