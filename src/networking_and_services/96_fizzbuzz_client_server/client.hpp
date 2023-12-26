#ifndef CLIENT_FIZZBUZZ_96
#define CLIENT_FIZZBUZZ_96
#include <boost/asio.hpp>
#include <fmt/format.h>
#include <iostream>
#include <ranges>

class Client
{
  private:
    boost::asio::ip::tcp::socket d_socket;

    void send(uint16_t i)
    {
        std::cout << "Client trying to send" << std::endl;
        d_socket.write_some(boost::asio::buffer(&i, sizeof(uint16_t)));
        std::cout << "Sent" << std::endl;
    }

    std::string getResponse()
    {
        std::string reply;
        reply.resize(1024);
        std::cout << "Waiting for response" << std::endl;
        try {
            auto size = d_socket.read_some(
                boost::asio::buffer(reply.data(), reply.size()));
            std::cout << "Response " << reply << " " << size << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        return reply;
    }

  public:
    Client(boost::asio::io_context &context,
        boost::asio::ip::tcp::endpoint endpoint)
        : d_socket(context)
    {

        boost::asio::ip::tcp::resolver resolver(context);
        auto resolv_result = resolver.resolve("127.0.0.1", "13");
        try {
            const auto ep = boost::asio::connect(d_socket, resolv_result);
        } catch (std::exception &e) {
            std::cout << "Error " << e.what() << std::endl;
        }
    }

    void run()
    {
        std::cout << "Running client " << std::endl;
        for (auto i : std::views::iota(1, 100)) {
            send(i);
            const auto response = getResponse();
            std::cout << fmt::format("Number {} => {}", i, response)
                      << std::endl;
        }
    }
};


#endif