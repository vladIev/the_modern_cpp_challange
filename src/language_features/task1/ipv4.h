#pragma once
#include <string_view>
#include <string>
#include <iostream>

class Ipv4
{
    int32_t d_address;

  public:
    Ipv4() = default;
    Ipv4(const Ipv4 &) = default;
    Ipv4(Ipv4 &&) = default;
    Ipv4(int32_t address);
    Ipv4(std::string_view address);

    Ipv4 &operator=(Ipv4 &&) = default;
    Ipv4 &operator=(const Ipv4 &) = default;

    auto as_string() const -> std::string;
    auto as_int() const -> int32_t;
};

std::ostream &operator<<(std::ostream &stream, const Ipv4 &ip);
std::istream &operator>>(std::istream &stream, Ipv4 &ip);
