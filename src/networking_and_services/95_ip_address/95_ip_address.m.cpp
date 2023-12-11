#include "95_ip_address.hpp"
#include "io_utils.h"

#include <ranges>
#include <string>

auto main(int argc, char **argv) -> int
{
    std::string_view invitation =
        "Program print ip address of the provided hostname. Enter hostname:";

    const auto hostname = utils::io::getUserInput<std::string>(invitation);
    const auto endpoints = getIpAddress(hostname);
    if (endpoints) {
        std::ranges::copy(
            *endpoints, std::ostream_iterator<std::string>(std::cout, "\n"));
    }
    return 0;
}