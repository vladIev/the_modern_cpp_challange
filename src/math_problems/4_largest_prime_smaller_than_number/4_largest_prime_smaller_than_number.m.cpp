#include "io_utils.h"
#include "largest_prime.hpp"

auto main(int argc, char **argv) -> int
{
    std::string_view invitation =
        "Program prints the largest prime number smaller than entered "
        "limit.\n"
        "Enter the limit:";
    const auto input = utils::io::getUserInput<uint32_t>(invitation);
    const auto output = getLargestPrime(input);
    utils::io::formatted_print(
        "The largest prime number smaller than {} is {}", input, output);

    return 0;
}