#include "math_utils.h"

#include <cmath>
#include <vector>

auto isAbundant(uint32_t number, uint64_t sumOfDivisors) -> bool
{
    return number < sumOfDivisors;
}

auto isAbundant(uint32_t number) -> bool
{
    const auto sumOfDivisors = utils::math::get_sum_of_divisors(number);
    return isAbundant(number, sumOfDivisors);
}

using abundant_and_abundance = std::pair<uint32_t, uint64_t>;
auto getAbundantsNumberUptoLimit(uint32_t limit)
    -> std::vector<abundant_and_abundance>
{
    std::vector<abundant_and_abundance> result;

    for (uint32_t i = 10; i < limit; i++) {
        const auto divisorsSum = utils::math::get_sum_of_divisors(i);
        if (isAbundant(i, divisorsSum)) {
            result.emplace_back(i, divisorsSum - i);
        }
    }

    return result;
}