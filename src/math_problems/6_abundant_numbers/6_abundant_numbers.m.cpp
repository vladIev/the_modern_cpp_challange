#include "abundant_numbers.hpp"
#include "io_utils.h"

#include <string_view>

auto printResult(uint32_t limit,
    const std::vector<abundant_and_abundance> &result) -> void
{
    if (result.empty()) {
        utils::io::formatted_print(
            "There is no abundant numbers up to the {}:", limit);
        return;
    }

    utils::io::formatted_print("Abundant numbers up to the {}:", limit);
    for (const auto &number : result) {
        utils::io::formatted_print("Abundant number {} with abundance {}",
            number.first,
            number.second);
    }
}

auto main(int argc, char **argv) -> int
{
    std::string_view invitation =
        "Program prints all abundant numbers and their abundance, up to a "
        "number entered by the user. An abundant number is number for which "
        "the sum of its proper divisors is greater than the number itself\n"
        "Enter the limit:";
    const auto input = utils::io::getUserInput<uint32_t>(invitation);
    const auto output = getAbundantsNumberUptoLimit(input);
    printResult(input, output);

    return 0;
}