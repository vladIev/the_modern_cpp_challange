#include "pascal_triangle.h"
#include "io_utils.h"

#include <iostream>
#include <string>
#include <vector>

auto main(int argc, char **argv) -> int
{
    std::string_view invitation =
        "Program prints pascal triangle of a given size\n "
        "Enter size of triangle: ";

    const auto size = utils::io::getUserInput<uint32_t>(invitation);
    const auto triangle = build_pascal_triangle(size);
    std::copy(triangle.begin(),
        triangle.end(),
        std::ostream_iterator<std::string>(std::cout, "\n"));
    return 0;
}