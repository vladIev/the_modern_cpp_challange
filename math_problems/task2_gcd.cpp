#include "io_utils.hpp"
#include "math_utils.hpp"


auto main(int argc, char **argv) -> int
{
    std::string_view invitation =
        "Program asks user to enter two numbers and prints their gratest "
        "common divisor\n"
        "Enter the first number:";

    const auto a = utils::io::getUserInput<int32_t>(invitation);
    const auto b = utils::io::getUserInput<int32_t>("Enter the second number:");
    const auto output = utils::math::gcd(a, b);

    utils::io::formatted_print("GCD of number {} {} is {}", a, b, output);
    return 0;
}