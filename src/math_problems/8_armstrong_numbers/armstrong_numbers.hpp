#include "math_utils.h"

#include <numeric>
#include <ranges>
#include <vector>
#include <cmath>

auto getLastDigit(uint32_t number) -> uint32_t { return number % 10; }

auto getDigits(uint32_t number) -> std::vector<uint32_t>
{
    if (number == 0) { return { 0 }; }
    std::vector<uint32_t> digits;
    while (number != 0) {
        digits.push_back(getLastDigit(number));
        number /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    return digits;
}

auto isArmstrongNumber(uint32_t number) -> bool
{
    if (number < 10) { return false; }

    const auto digits = getDigits(number);
    const auto pows = digits
        | std::views::transform(
            [pow = digits.size()](uint32_t num) -> uint64_t {
                uint64_t multiplied = num;
                for (auto i = 1U; i < pow; i++) { multiplied *= num; }
                return multiplied;
            });

    const auto armstrongSum =
        std::accumulate(pows.begin(), pows.end(), static_cast<uint64_t>(0));
    return number == armstrongSum;
}

auto armstrongNumbersInRange(uint32_t start, uint32_t end)
    -> std::vector<uint32_t>
{
    auto result = std::ranges::iota_view{ start, end }
        | std::views::filter(
            [](uint32_t num) { return isArmstrongNumber(num); });

    std::vector<uint32_t> output(result.begin(), result.end());
    return output;
}