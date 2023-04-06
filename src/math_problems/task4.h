#include "math_utils.h"

#include <cassert>

uint32_t get_largest_prime(uint32_t limit)
{
    assert(limit > 1);
    for (auto i = limit - 1; i > 1; i--) {
        if (utils::math::is_prime(i)) { return i; }
    }
    return 1;
}