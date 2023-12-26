#include "client.hpp"

#include <boost/asio.hpp>

auto main(int argc, char **argv) -> int
{
    boost::asio::io_context clientContext;
    auto client = Client(clientContext, boost::asio::ip::tcp::endpoint());
    client.run();
    clientContext.run();
    return 0;
}
