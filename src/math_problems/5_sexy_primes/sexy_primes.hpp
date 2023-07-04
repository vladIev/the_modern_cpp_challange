#include "math_utils.h"

#include <vector>

using SexyPrimes = std::vector<std::pair<uint32_t, uint32_t>>;
SexyPrimes getAllSexyPrimesUptoLimit(uint32_t limit)
{
    SexyPrimes sexyPrimes;
    for (uint32_t i = 3; i + 6 <= limit; i += 2) {
        if (utils::math::is_prime(i) && utils::math::is_prime(i + 6)) {
            sexyPrimes.push_back({ i, i + 6 });
        }
    }
    return sexyPrimes;
}