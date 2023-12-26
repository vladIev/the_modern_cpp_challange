#include "server.hpp"

#include <boost/asio.hpp>
#include <chrono>
#include <thread>

auto main(int argc, char **argv) -> int
{
    boost::asio::io_context context;
    const auto endpoint =
        boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 13);
    std::cout << "Starting listening" << std::endl;
    auto server = Server(context, 13);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    context.run();

    return 0;
}
