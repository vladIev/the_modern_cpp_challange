#include <vector>
#include <limits>
#include <iostream>

auto calculateNext(uint32_t value) -> uint32_t
{
    return value & 1 ? value * 3 + 1 : value / 2;
}

auto longestCollatz(uint32_t limit) -> std::pair<uint32_t, uint32_t>
{
    std::vector<uint32_t> cache(limit + 1, 0);

    uint32_t maxLength = 1;
    uint32_t maxNumber = 0;

    for (uint32_t i = 2; i < limit; i++) {
        auto n = i;
        auto length = 0;
        while (n != 1 && n >= i) {
            n = calculateNext(n);
            length++;
        }
        cache[i] = length + cache[n];

        if (cache[i] > maxLength) {
            maxLength = cache[i];
            maxNumber = i;
        }
    }

    return std::pair(maxNumber, maxLength);
}
