#include "math_utils.h"

#include <cmath>
#include <vector>

auto is_abundant(uint32_t number, uint64_t sum_of_divisors) -> bool
{
    return number < sum_of_divisors;
}

auto is_abundant(uint32_t number) -> bool
{
    const auto sum_of_divisors = utils::math::get_sum_of_divisors(number);
    return is_abundant(number, sum_of_divisors);
}

using abundant_and_abundance = std::pair<uint32_t, uint64_t>;
auto get_abundants_number_upto_limit(uint32_t limit)
    -> std::vector<abundant_and_abundance>
{
    std::vector<abundant_and_abundance> result;

    for (uint32_t i = 10; i < limit; i++) {
        const auto divisors_sum = utils::math::get_sum_of_divisors(i);
        if (is_abundant(i, divisors_sum)) {
            result.push_back({ i, divisors_sum - i });
        }
    }

    return result;
}