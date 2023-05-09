#pragma once
#include <concepts>
#include <iostream>
#include <ranges>
#include <type_traits>

namespace utils {

template<typename T>
concept CinEnterable = requires(T value) { std::cin >> value; };

template<typename T>
concept Iteratable = std::ranges::range<T>;

template<typename Func, typename... Args>
concept ReturnsVoid = requires(Func f, Args... args) {
    {
        f(args...)
    } -> std::same_as<void>;
};

template<typename Func, typename... Args>
concept ReturnsNotVoid = !ReturnsVoid<Func, Args...>;

}// namespace utils