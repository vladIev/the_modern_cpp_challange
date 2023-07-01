#include "isbn.hpp"

#include <gtest/gtest.h>

TEST(isbn_validator, positive)
{
    EXPECT_TRUE(IsbnValidator::validate("3161484118"));
    EXPECT_TRUE(IsbnValidator::validate("0000000019"));
    EXPECT_TRUE(IsbnValidator::validate("0000000000"));
}

TEST(isbn_validator, negative)
{
    EXPECT_FALSE(IsbnValidator::validate("3161484100"));
    EXPECT_FALSE(IsbnValidator::validate("0000000001"));
    EXPECT_FALSE(IsbnValidator::validate("1111111211"));
}

TEST(isbn_validator, ilformatted)
{
    EXPECT_FALSE(IsbnValidator::validate(""));
    EXPECT_FALSE(IsbnValidator::validate("123"));
    EXPECT_FALSE(IsbnValidator::validate("0-000000000"));
    EXPECT_FALSE(IsbnValidator::validate("abcdefghij"));
}