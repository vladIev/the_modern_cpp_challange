#include "88_ceaser_cipher.h"

#include <string_view>

#include <gtest/gtest.h>

TEST(caeser_cipher, encode)
{
    constexpr std::string_view testPhrase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    constexpr uint8_t offset = 3;
    constexpr std::string_view expected = "DEFGHIJKLMNOPQRSTUVWXYZABC";

    EXPECT_EQ(ceaserEncrypt(testPhrase, offset), expected);
}

TEST(caeser_cipher, decode)
{
    constexpr std::string_view testPhrase = "DEFGHIJKLMNOPQRSTUVWXYZABC";
    constexpr std::string_view expected = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    constexpr uint8_t offset = 3;

    EXPECT_EQ(ceaserDecrypt(testPhrase, offset), expected);
}

TEST(caeser_cipher, skip_non_letters)
{
    constexpr std::string_view testPhrase = "A1234567890!., \n";
    constexpr uint8_t offset = 3;
    constexpr std::string_view expected = "D1234567890!., \n";

    EXPECT_EQ(ceaserEncrypt(testPhrase, offset), expected);
    EXPECT_EQ(ceaserDecrypt(expected, offset), testPhrase);
}

TEST(caeser_cipher, skip_lower_letters)
{
    constexpr std::string_view testPhrase = "abcdefghijklmnopqrstuvwxyz";
    constexpr uint8_t offset = 3;

    EXPECT_EQ(ceaserEncrypt(testPhrase, offset), testPhrase);
    EXPECT_EQ(ceaserDecrypt(testPhrase, offset), testPhrase);
}