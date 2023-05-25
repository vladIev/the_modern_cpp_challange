#pragma once
#include "concepts.h"

#include <iomanip>
#include <sstream>

template<utils::Iteratable Ints>
auto ints_to_hex(Ints ints, bool use_uppercase = true)
{
    std::stringstream ss;
    if (use_uppercase) { ss.setf(std::ios_base::uppercase); }
    for (auto val : ints) {
        ss << std::hex << std::setw(2) << std::setfill('0') << val;
    }
    return ss.str();
}