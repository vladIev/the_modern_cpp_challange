#include "sexy_primes.hpp"
#include "io_utils.h"

#include <string_view>

auto printResult(uint32_t limit, const SexyPrimes &result) -> void
{
    if (result.empty()) {
        utils::io::formatted_print(
            "There is no pairs of sexy prime numbers up to the {}:", limit);
        return;
    }

    utils::io::formatted_print("Pairs of the sexy primes up to the {}:", limit);
    for (const auto &sexyPair : result) {
        utils::io::formatted_print(
            "{} and {}", sexyPair.first, sexyPair.second);
    }
}

auto main(int argc, char **argv) -> int
{
    std::string_view invitation =
        "Program prints all pairs of the sexy primes numbers up to the entered "
        "limit. Sexy prime numbers are prime numbers that differ from each "
        "other by six\n"
        "Enter the limit:";
    const auto input = utils::io::getUserInput<uint32_t>(invitation);
    const auto output = getAllSexyPrimesUptoLimit(input);
    printResult(input, output);

    return 0;
}