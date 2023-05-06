#include <string>
#include <string_view>
#include <vector>

namespace utils {
namespace str {
    auto split_string(std::string_view str, char separator = ' ')
        -> std::vector<std::string_view>
    {
        std::vector<std::string_view> substrings;
        size_t start = 0;
        size_t end = str.find(separator);
        while (end != std::string_view::npos) {
            substrings.push_back(str.substr(start, end - start));
            start = end + 1;
            end = str.find(separator, start);
        }
        substrings.push_back(str.substr(start));
        return substrings;
    }
}// namespace str
}// namespace utils