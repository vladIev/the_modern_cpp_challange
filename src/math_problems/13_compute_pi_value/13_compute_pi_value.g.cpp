#include "compute_pi.hpp"

#include <random>
#include <gtest/gtest.h>

TEST(compute_pi, two_digits_test)
{
    std::random_device rd;
    std::mt19937 mt(42);
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    EXPECT_DOUBLE_EQ(3.14, std::round(computePi(mt, dist) * 100) / 100);
}
