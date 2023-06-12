#include "io_utils.h"
#include "prime_factors.hpp"

#include <string_view>
#include <vector>

auto printResult(uint64_t number, const std::vector<uint64_t> &result) -> void
{
    utils::io::formatted_print("Prime factors of number {}:", number);
    for (const auto &number : result) {
        utils::io::formatted_print("{}", number);
    }
}

auto main(int argc, char **argv) -> int
{
    std::string_view invitation =
        "Program prints prime factors of a given number.\n"
        "Enter the nubmer:";
    const auto input = utils::io::getUserInput<uint64_t>(invitation);
    const auto output = primeFactors(input);
    printResult(input, output);

    return 0;
}