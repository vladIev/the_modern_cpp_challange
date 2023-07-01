#include "armstrong_numbers.hpp"
#include <gtest/gtest.h>


TEST(task8_tests, get_last_digit_test)
{
    using input_and_expected_t = std::pair<uint32_t, uint32_t>;
    const std::vector<input_and_expected_t> test_data{
        { 0, 0 }, { 5, 5 }, { 21, 1 }, { 5432, 2 }, { 6543, 3 }
    };

    for (const auto &[input, expected] : test_data) {
        EXPECT_EQ(get_last_digit(input), expected);
    }
}

TEST(task8_tests, get_digits_test)
{
    using input_and_expected_t = std::pair<uint32_t, std::vector<uint32_t>>;
    const std::vector<input_and_expected_t> test_data{ { 0, { 0 } },
        { 5, { 5 } },
        { 21, { 2, 1 } },
        { 5432, { 5, 4, 3, 2 } },
        { 1624321, { 1, 6, 2, 4, 3, 2, 1 } } };

    for (const auto &[input, expected] : test_data) {
        EXPECT_EQ(get_digits(input), expected);
    }
}

TEST(task8_tests, is_armstrong_number_test)
{
    using input_and_expected_t = std::pair<uint32_t, bool>;
    const std::vector<input_and_expected_t> test_data{ { 152, false },
        { 0, false },
        { 1, false },
        { 153, true },
        { 370, true },
        { 1634, true },
        { 1741725, true } };

    for (const auto &[input, expected] : test_data) {
        EXPECT_EQ(is_armstrong_number(input), expected)
            << "For value " << input;
    }
}

TEST(task8_tests, armstrong_numbers_in_range_test)
{
    const std::pair<uint32_t, uint32_t> test_range{ 100, 400 };
    const std::vector<uint32_t> expected{ 153, 370, 371 };
    const auto armstrong_numbers =
        armstrong_numbers_in_range(test_range.first, test_range.second);
    EXPECT_EQ(armstrong_numbers, expected);
}
