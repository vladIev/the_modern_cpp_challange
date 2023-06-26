#include "numbers_to_roman.hpp"

#include <gtest/gtest.h>

TEST(to_romans, breathing)
{
    EXPECT_EQ(toRoman(1), std::string_view("I"));
    EXPECT_EQ(toRoman(3), std::string_view("III"));
    EXPECT_EQ(toRoman(4), std::string_view("IV"));
    EXPECT_EQ(toRoman(5), std::string_view("V"));
    EXPECT_EQ(toRoman(6), std::string_view("VI"));
    EXPECT_EQ(toRoman(9), std::string_view("IX"));
    EXPECT_EQ(toRoman(10), std::string_view("X"));
    EXPECT_EQ(toRoman(11), std::string_view("XI"));
    EXPECT_EQ(toRoman(40), std::string_view("XL"));
    EXPECT_EQ(toRoman(50), std::string_view("L"));
    EXPECT_EQ(toRoman(90), std::string_view("XC"));
    EXPECT_EQ(toRoman(100), std::string_view("C"));
    EXPECT_EQ(toRoman(400), std::string_view("CD"));
    EXPECT_EQ(toRoman(500), std::string_view("D"));
    EXPECT_EQ(toRoman(900), std::string_view("CM"));
    EXPECT_EQ(toRoman(1000), std::string_view("M"));
    EXPECT_EQ(toRoman(1999), std::string_view("MCMXCIX"));
    EXPECT_EQ(toRoman(1452), std::string_view("MCDLII"));
}