#include "math_utils.hpp"

#include <vector>

using sexy_primes = std::vector<std::pair<uint32_t, uint32_t>>;
sexy_primes get_all_sexy_primes_upto_limit(uint32_t limit)
{
    sexy_primes sexy_primes;
    for (uint32_t i = 3; i + 6 <= limit; i += 2) {
        if (utils::math::is_prime(i) && utils::math::is_prime(i + 6)) {
            sexy_primes.push_back({ i, i + 6 });
        }
    }
    return sexy_primes;
}