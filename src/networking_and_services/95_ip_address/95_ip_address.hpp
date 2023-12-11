#ifndef IP_ADDRESS_95
#define IP_ADDRESS_95
#include <boost/asio.hpp>
#include <fmt/core.h>

#include <iostream>
#include <string>
#include <vector>

auto getIpAddress(std::string_view hostname)
    -> std::optional<std::vector<std::string>>
{
    std::vector<std::string> ips;
    try {
        boost::asio::io_context context;
        boost::asio::ip::tcp::resolver resolver(context);
        const auto endpoints =
            resolver.resolve(boost::asio::ip::tcp::v4(), hostname.data(), "");

        ips.reserve(endpoints.size());
        std::transform(endpoints.begin(),
            endpoints.end(),
            std::back_inserter(ips),
            [](const auto &endpoint) {
                return static_cast<boost::asio::ip::tcp::endpoint>(endpoint)
                    .address()
                    .to_string();
            });
    } catch (const std::exception &e) {
        std::cerr << fmt::format(
            "Can't get ip address of the {}. Reason: ", hostname, e.what());
        return std::nullopt;
    }

    return { ips };
}

#endif