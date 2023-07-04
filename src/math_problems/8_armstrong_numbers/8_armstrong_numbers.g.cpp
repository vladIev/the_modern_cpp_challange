#include "armstrong_numbers.hpp"
#include <gtest/gtest.h>


TEST(task8_tests, get_last_digit_test)
{
    using input_and_expected_t = std::pair<uint32_t, uint32_t>;
    const std::vector<input_and_expected_t> testData{
        { 0, 0 }, { 5, 5 }, { 21, 1 }, { 5432, 2 }, { 6543, 3 }
    };

    for (const auto &[input, expected] : testData) {
        EXPECT_EQ(getLastDigit(input), expected);
    }
}

TEST(task8_tests, get_digits_test)
{
    using input_and_expected_t = std::pair<uint32_t, std::vector<uint32_t>>;
    const std::vector<input_and_expected_t> testData{ { 0, { 0 } },
        { 5, { 5 } },
        { 21, { 2, 1 } },
        { 5432, { 5, 4, 3, 2 } },
        { 1624321, { 1, 6, 2, 4, 3, 2, 1 } } };

    for (const auto &[input, expected] : testData) {
        EXPECT_EQ(getDigits(input), expected);
    }
}

TEST(task8_tests, is_armstrong_number_test)
{
    using input_and_expected_t = std::pair<uint32_t, bool>;
    const std::vector<input_and_expected_t> testData{ { 152, false },
        { 0, false },
        { 1, false },
        { 153, true },
        { 370, true },
        { 1634, true },
        { 1741725, true } };

    for (const auto &[input, expected] : testData) {
        EXPECT_EQ(isArmstrongNumber(input), expected) << "For value " << input;
    }
}

TEST(task8_tests, armstrong_numbers_in_range_test)
{
    const std::pair<uint32_t, uint32_t> testRange{ 100, 400 };
    const std::vector<uint32_t> expected{ 153, 370, 371 };
    const auto armstrongNumbers =
        armstrongNumbersInRange(testRange.first, testRange.second);
    EXPECT_EQ(armstrongNumbers, expected);
}
