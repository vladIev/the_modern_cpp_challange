#include "io_utils.h"
#include "task10_graycode.h"

#include <string_view>
#include <vector>
#include <tuple>

auto print_result(const auto &result) -> void
{
    utils::io::formatted_print("Binary - Encoded - decoded:");
    for (const auto &numbers : result) {
        utils::io::formatted_print("{} - {} - {}",
            std::get<0>(numbers),
            std::get<1>(numbers),
            std::get<2>(numbers));
    }
}

auto main(int argc, char **argv) -> int
{
    std::string_view invitation =
        "Program prints binary representation, gray encoded and gray decoded "
        "values up to 32.\n ";
    utils::io::formatted_print(invitation);
    const auto output = solution(5);
    print_result(output);
    return 0;
}