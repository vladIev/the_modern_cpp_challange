#include "password_validator.h"

#include <gtest/gtest.h>

constexpr auto minLength = 5u;
constexpr auto maxLength = 20u;
constexpr auto minNumOfUpperCase = 1u;
constexpr auto minNumOfLowerCase = 1u;
constexpr auto minNumOfDigits = 1u;
constexpr auto minNumOfLetters = 1u;
constexpr auto minNumOfSigns = 1u;

using DefaultPasswordValidator =
    PasswordValidator<LengthValidator<minLength, maxLength>,
        CaseValidator<minNumOfUpperCase, minNumOfLowerCase>,
        CharsValidator<minNumOfDigits, minNumOfLetters, minNumOfSigns>>;

TEST(password_validator, default_validator)
{
    EXPECT_FALSE(DefaultPasswordValidator::validate("a"))
        << "Short password passed";
    EXPECT_FALSE(DefaultPasswordValidator::validate("aa!1aa"))
        << "Password without Uppercase passed";
    EXPECT_FALSE(DefaultPasswordValidator::validate("aaa!A"))
        << "Password without digits passed";
    EXPECT_FALSE(DefaultPasswordValidator::validate("aaaaA1"))
        << "Password without signs passed";
    EXPECT_FALSE(DefaultPasswordValidator::validate("aA!12345678901234567890"))
        << "Long password passed";
    EXPECT_TRUE(DefaultPasswordValidator::validate("aaaaA1!"))
        << "Valid password failed";
    EXPECT_TRUE(DefaultPasswordValidator::validate("aBc123!!8u2132"))
        << "Valid password failed";
}

TEST(password_validator, default_validator_with_customization)
{
    const auto substr = std::string_view("abc");
    const auto checkSubstr = [&](std::string_view password) {
        return password.find(substr) != std::string::npos;
    };
    EXPECT_TRUE(
        DefaultPasswordValidator::validate("abc123!!8U132", checkSubstr))
        << "Valid password failed";
}