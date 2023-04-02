#include "io_utils.h"
#include "math_utils.h"

int main(int argc, char **argv)
{
    std::string_view invitation =
        "Program asks user to enter two numbers and prints their least "
        "common multiple\n"
        "Enter the first number:";

    const auto a = utils::io::getUserInput<int32_t>(invitation);
    const auto b = utils::io::getUserInput<int32_t>("Enter the second number:");
    utils::io::formatted_print(
        "LCM of number {} {} is {}", a, b, utils::math::lcm(a, b));

    return 0;
}