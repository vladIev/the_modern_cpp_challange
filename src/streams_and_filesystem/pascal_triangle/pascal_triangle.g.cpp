#include "pascal_triangle.h"

#include <vector>
#include <string>

#include <gtest/gtest.h>

TEST(pascal_triangle_test, happy_path)
{
    const uint32_t size = 5;
    // clang-format off
    const std::vector<std::string> expected{
        "        1   ",
        "      1   1   ",
        "    1   2   1   ",
        "  1   3   3   1   ",
        "1   4   6   4   1   " 
    };
    // clang-format on
    const auto actual = build_pascal_triangle(size);
    EXPECT_EQ(actual, expected);
}