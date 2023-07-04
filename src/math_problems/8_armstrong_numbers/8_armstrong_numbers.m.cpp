#include "io_utils.h"
#include "armstrong_numbers.hpp"

#include <string_view>
#include <vector>

auto printResult(uint32_t limit, const std::vector<uint32_t> &result) -> void
{
    if (result.empty()) {
        utils::io::formatted_print(
            "There is no Armstrong numbers up to the {}:", limit);
        return;
    }

    utils::io::formatted_print("Armstrong numbers up to the {}:", limit);
    for (const auto &number : result) {
        utils::io::formatted_print("{}", number);
    }
}

auto main(int argc, char **argv) -> int
{
    const auto limit = 1'000;
    std::string_view invitation =
        "Program prints all armstrong numbers up to 1000.\n ";
    utils::io::formatted_print(invitation);
    const auto output = armstrongNumbersInRange(0, limit);
    printResult(limit, output);

    return 0;
}