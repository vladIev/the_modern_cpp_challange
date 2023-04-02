#include <string_view>

auto calculateSum(uint32_t limit)
{
    uint64_t sum = 0;
    for (uint32_t nextNum = 3; nextNum < limit; nextNum += 3) {
        sum += nextNum;
    }

    for (uint32_t nextNum = 5; nextNum < limit; nextNum += 5) {
        if (nextNum % 3 != 0) { sum += nextNum; }
    }
    return sum;
}