#include <array>
#include <utility>
#include <string>

constexpr auto getIntToRomanMapping()
    -> std::array<std::pair<uint32_t, std::string_view>, 13>
{
    using MapPair = std::pair<uint32_t, std::string_view>;
    // clang-format off
    return
    {
        MapPair(1000u, "M"), MapPair(900u, "CM"),
        MapPair(500u, "D"),  MapPair(400u, "CD"),
        MapPair(100u, "C"),  MapPair(90u, "XC"),
        MapPair(50u, "L"),   MapPair(40u, "XL"),
        MapPair(10u, "X"),   MapPair(9u, "IX"),
        MapPair(5u, "V"),    MapPair(4u, "IV"),
        MapPair(1u, "I")
    };
    // clang-format on
}

auto toRoman(uint32_t value) -> std::string
{
    static constexpr auto romanNums = getIntToRomanMapping();

    std::string result;
    auto it = romanNums.begin();
    while (value != 0) {
        while (value >= it->first) {
            result += it->second;
            value -= it->first;
        }
        it++;
    }
    return result;
}