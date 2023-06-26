#include "io_utils.h"
#include "numbers_to_roman.hpp"

#include <string_view>
#include <vector>

auto main(int argc, char **argv) -> int
{
    std::string_view invitation =
        "Program prints roman representation of a given number.\n"
        "Enter the nubmer:";
    const auto input = utils::io::getUserInput<uint32_t>(invitation);
    const auto output = toRoman(input);
    utils::io::formatted_print(
        "The roman representation of value {} is {}", input, output);
    return 0;
}