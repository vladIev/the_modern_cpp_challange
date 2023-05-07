#include <iostream>
#include <vector>
#include <string>

uint32_t number_of_digits(uint32_t n)
{
    return n > 0 ? static_cast<uint32_t>(log10(static_cast<double>(n))) + 1 : 1;
}

auto build_pascal_triangle(uint32_t n) -> std::vector<std::string>
{
    std::vector<std::string> triangle;
    triangle.reserve(n);
    for (auto i = 0u; i < n; i++) {
        std::string row((n - i - 1) * (n / 2), ' ');
        auto x = 1;
        for (auto j = 0u; j <= i; j++) {
            const auto y = x;
            x = x * (i - j) / (j + 1);
            const auto maxlen = number_of_digits(x) - 1;
            row += std::to_string(y) + std::string(n - 1 - maxlen - n % 2, ' ');
        }
        triangle.emplace_back(std::move(row));
    }
    return triangle;
}
