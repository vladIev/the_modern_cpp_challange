#pragma once
#include <concepts>
#include <iostream>

namespace utils {

template <typename T>
concept CinEnterable = requires(T value) {
  std::cin >> value;
};
} // namespace utils