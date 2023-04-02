#include "task6_abundant_numbers.h"
#include "io_utils.h"

#include <string_view>

auto print_result(uint32_t limit,
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
    const auto output = get_abundants_number_upto_limit(input);
    print_result(input, output);

    return 0;
}