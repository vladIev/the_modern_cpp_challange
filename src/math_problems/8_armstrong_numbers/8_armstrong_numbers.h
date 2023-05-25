#include "math_utils.h"

#include <numeric>
#include <ranges>
#include <vector>
#include <cmath>

auto get_last_digit(uint32_t number) -> uint32_t { return number % 10; }

auto get_digits(uint32_t number) -> std::vector<uint32_t>
{
    if (number == 0) { return { 0 }; }
    std::vector<uint32_t> digits;
    while (number != 0) {
        digits.push_back(get_last_digit(number));
        number /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    return digits;
}

auto is_armstrong_number(uint32_t number) -> bool
{
    if (number < 10) { return false; }

    const auto digits = get_digits(number);
    const auto pows = digits
        | std::views::transform(
            [pow = digits.size()](uint32_t num) -> uint64_t {
                uint64_t multiplied = num;
                for (auto i = 1u; i < pow; i++) { multiplied *= num; }
                return multiplied;
            });

    const auto armstrong_sum =
        std::accumulate(pows.begin(), pows.end(), static_cast<uint64_t>(0));
    return number == armstrong_sum;
}

auto armstrong_numbers_in_range(uint32_t start, uint32_t end)
    -> std::vector<uint32_t>
{
    auto result = std::ranges::iota_view{ start, end }
        | std::views::filter(
            [](uint32_t num) { return is_armstrong_number(num); });

    std::vector<uint32_t> output(result.begin(), result.end());
    return output;
}