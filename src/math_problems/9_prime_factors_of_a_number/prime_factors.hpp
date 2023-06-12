#include <vector>
#include <cmath>

auto primeFactors(uint64_t number) -> std::vector<uint64_t>
{
    std::vector<uint64_t> factors;
    while (number % 2 == 0) {
        factors.push_back(2);
        number = number / 2;
    }

    for (uint64_t i = 3; i <= std::sqrt(number); i += 2) {
        while (number % i == 0) {
            factors.push_back(i);
            number = number / i;
        }
    }

    if (number > 2) { factors.push_back(number); }
    return factors;
}