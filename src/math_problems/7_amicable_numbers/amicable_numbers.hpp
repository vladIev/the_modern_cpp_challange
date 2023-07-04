#include "math_utils.h"

#include <vector>

using amicable_numbers = std::pair<uint32_t, uint32_t>;
using amicable_pairs = std::vector<amicable_numbers>;
auto getAmicablesNumberUptoLimit(const auto limit) -> amicable_pairs
{
    std::vector<std::pair<uint32_t, uint32_t>> result;
    for (uint32_t i = 4; i < limit; i++) {
        const auto sum1 = utils::math::get_sum_of_divisors(i);
        if (sum1 < limit && sum1 != i) {
            const auto sum2 = utils::math::get_sum_of_divisors(sum1);
            if (sum2 == i && sum1 > i) { result.push_back({ i, sum1 }); }
        }
    }
    return result;
}