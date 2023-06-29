#include "ipv4.h"
#include "str_utils.h"

#include <optional>
#include <fmt/core.h>

namespace {
auto str_to_int(std::string_view str) -> std::optional<int32_t>
{
    try {
        int result = std::stoi(std::string(str));
        if (result >= 0 && result <= 255) { return result; }
    } catch (...) {}
    return std::nullopt;
}

auto ip_str_to_int(std::string_view str) -> int32_t
{
    const auto nums = utils::str::split_string(str, '.');
    if (nums.size() != 4) {
        throw std::invalid_argument(fmt::format("Invalid IP address {}", str));
    }
    int32_t result = 0;
    int32_t offset = 24;
    for (auto num : nums) {
        auto part = str_to_int(num);
        if (!part) {
            throw std::invalid_argument(
                fmt::format("Invalid IP address {}", str));
        }
        result |= part.value() << offset;
        offset -= 8;
    }
    return result;
}
}// namespace

Ipv4::Ipv4(int32_t address) : d_address(address) {}
Ipv4::Ipv4(std::string_view address) : d_address(ip_str_to_int(address)) {}

std::string Ipv4::as_string() const
{
    std::string result;
    for (int32_t offset = 24; offset >= 0; offset -= 8) {
        result += std::to_string((d_address >> offset) & 0xFF);
        result += '.';
    }
    result.pop_back();
    return result;
}

auto Ipv4::as_int() const -> int32_t { return d_address; }

std::ostream &operator<<(std::ostream &stream, const Ipv4 &ip)
{
    stream << ip.as_string();
    return stream;
}

std::istream &operator>>(std::istream &stream, Ipv4 &ip)
{
    std::string str;
    stream >> str;
    ip = Ipv4(str);
    return stream;
}
