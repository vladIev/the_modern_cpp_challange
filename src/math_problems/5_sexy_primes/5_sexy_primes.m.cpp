#include "5_sexy_primes.h"
#include "io_utils.h"

#include <string_view>

auto print_result(uint32_t limit, const sexy_primes &result) -> void
{
    if (result.empty()) {
        utils::io::formatted_print(
            "There is no pairs of sexy prime numbers up to the {}:", limit);
        return;
    }

    utils::io::formatted_print("Pairs of the sexy primes up to the {}:", limit);
    for (const auto &sexy_pair : result) {
        utils::io::formatted_print(
            "{} and {}", sexy_pair.first, sexy_pair.second);
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
    const auto output = get_all_sexy_primes_upto_limit(input);
    print_result(input, output);

    return 0;
}