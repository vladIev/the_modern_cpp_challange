#include "io_utils.hpp"
#include "task1.h"

auto main(int argc, char **argv) -> int
{
    std::string_view invitation =
        "Program calculates and prints the sum of all the natural "
        "numbers divisible by either 3 or 5, up to a given limit "
        "entererd by the user.\n"
        "Enter the limit:";
    const auto input = utils::io::getUserInput<uint32_t>(invitation);
    utils::io::formatted_print("The sum is {}", calculateSum(input));
    return 0;
}