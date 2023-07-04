#include "io_utils.h"
#include "amicable_numbers.hpp"

#include <string_view>
#include <vector>

auto printResult(uint32_t limit, const amicable_pairs &result) -> void
{
    if (result.empty()) {
        utils::io::formatted_print(
            "There is no amicable numbers up to the {}:", limit);
        return;
    }

    utils::io::formatted_print("Amicable numbers up to the {}:", limit);
    for (const auto &number : result) {
        utils::io::formatted_print(
            "Amicable numbers {} - {}", number.first, number.second);
    }
}

auto main(int argc, char **argv) -> int
{
    const auto LIMIT = 1'000'000;
    std::string_view invitation =
        "Program prints all amicable pairs of numbers tu to a millon."
        "Two numbers are abicable fi the sum of the proper divisors of one "
        "number is equal to that of the other number itself\n";
    utils::io::formatted_print(invitation);
    const auto output = getAmicablesNumberUptoLimit(LIMIT);
    printResult(LIMIT, output);

    return 0;
}