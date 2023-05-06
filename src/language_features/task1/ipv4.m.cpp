#include "ipv4.h"
#include "io_utils.h"

auto main(int argc, char **argv) -> int
{
    std::string_view invitation =
        "Program asks user to enter IP, than prints it int representation."
        "Enter the IP: ";
    const auto input = utils::io::getUserInput<std::string>(invitation);
    const auto ip = Ipv4(input);
    utils::io::formatted_print(
        "Entererd IP: {}. As int {}", ip.as_string(), ip.as_int());
    return 0;
}