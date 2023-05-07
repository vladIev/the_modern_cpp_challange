#include "ints_to_hex_repr.h"
#include "io_utils.h"
#include <iostream>

#include <vector>

auto main(int argc, char **argv) -> int
{
    std::string_view invitation =
        "Program prints given hexadecimal representation of input data: a "
        "range of ints\n "
        "Enter the number of input numbers and than numbers: ";

    const auto size = utils::io::getUserInput<size_t>(invitation);
    std::vector<int> input(size);
    for (int i = 0; i < size; i++) {
        input[i] = utils::io::getUserInput<int>();
    }
    utils::io::formatted_print(
        "The  hexadecimal representation  is {}", ints_to_hex(input));
    return 0;
}