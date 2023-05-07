#pragma once
#include <fstream>
#include <iostream>
#include <limits>
#include <string_view>
#include <format>

#include "concepts.h"

namespace utils {
namespace io {
    template<utils::CinEnterable ReturnType>
    auto getUserInput(std::string_view userInvitation = "") -> ReturnType
    {
        if (!userInvitation.empty()) {
            std::cout << userInvitation << std::endl;
        }
        ReturnType input{ 0 };

        while (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input" << std::endl;
            if constexpr (std::is_arithmetic_v<ReturnType>) {
                std::cout << "Expected number in range ["
                          << std::numeric_limits<ReturnType>::min() << ", "
                          << std::numeric_limits<ReturnType>::max() << "]"
                          << std::endl;
            }
        }
        return input;
    }

    template<typename... Args>
    void formatted_print(std::string_view fmt, Args &&...args)
    {
        std::cout << std::vformat(
            fmt, std::make_format_args(std::forward<Args>(args)...))
                  << std::endl;
    }
}// namespace io
}// namespace utils