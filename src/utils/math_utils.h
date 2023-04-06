#pragma once
#include <cassert>
#include <cstdint>
#include <cmath>

namespace utils {
namespace math {
    auto gcd_solver(int32_t a, int32_t b) -> int32_t
    {
        a = a % b;
        return a != 0 ? gcd_solver(b, a) : b;
    }
    auto gcd(int32_t a, int32_t b) -> int32_t
    {
        assert(a != 0 && b != 0);
        return gcd_solver(a, b);
    }

    auto lcm(int32_t a, int32_t b) -> int64_t
    {
        return abs(a * b) / utils::math::gcd(a, b);
    }

    auto is_prime(uint32_t val) -> bool
    {
        if (val <= 3) return val > 1;
        if (val % 2 == 0 || val % 3 == 0) return false;

        for (uint64_t i = 5; i * i <= val; i += 6) {
            if (val % i == 0 || val % (i + 2) == 0) { return false; }
        }

        return true;
    }

    auto get_sum_of_divisors(uint32_t number) -> uint64_t
    {
        uint64_t result = 1;
        const auto num_sqrt = static_cast<uint32_t>(std::sqrt(number));
        for (auto i = 2u; i <= num_sqrt; i++) {
            if (number % i == 0) {
                const auto div_result = number / i;
                result += i;
                if (div_result != i) { result += div_result; }
            }
        }
        return result;
    }
}// namespace math
}// namespace utils
