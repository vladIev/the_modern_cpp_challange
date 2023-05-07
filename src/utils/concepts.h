#pragma once
#include <concepts>
#include <iostream>
#include <ranges>

namespace utils {

template<typename T>
concept CinEnterable = requires(T value) { std::cin >> value; };

template<typename T>
concept Iteratable = std::ranges::range<T>;
}// namespace utils