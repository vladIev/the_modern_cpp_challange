#ifndef SERVER_FIZZBUZZ_96
#define SERVER_FIZZBUZZ_96
#include <boost/asio.hpp>
#include <fmt/format.h>
#include <iostream>
#include <memory>
#include <mutex>
#include <ranges>
#include <unordered_set>

static std::string fizzbuzz(int number)
{
    const bool isFizz = number % 3 == 0;
    const bool isBuzz = number % 5 == 0;
    if (!isFizz && !isBuzz) { return std::to_string(number); }
    if (isFizz && isBuzz) { return "fizzbuzz"; }
    if (isFizz) { return "fizz"; }
    return "buzz";
}

class Session : public std::enable_shared_from_this<Session>
{
  private:
    int d_data;
    boost::asio::ip::tcp::socket d_socket;

    void read()
    {
        auto self = shared_from_this();
        d_socket.async_read_some(boost::asio::buffer(&d_data, sizeof(d_data)),
            [self](std::error_code ec, std::size_t) {
                if (!ec) {
                    const auto result = fizzbuzz(self->d_data);
                    std::cout << fmt::format("{} -> {}", self->d_data, result)
                              << std::endl;
                    self->write(result);
                }
            });
    }

    void write(std::string_view response)
    {
        auto self = shared_from_this();
        d_socket.async_write_some(
            boost::asio::buffer(response.data(), response.length()),
            [self](std::error_code ec, std::size_t) {
                if (!ec) { self->read(); }
            });
    }

  public:
    Session(boost::asio::ip::tcp::socket socket)
        : d_socket(std::move(socket)), d_data(0)
    {}
    void start() { read(); }
};

class Server
{
    boost::asio::ip::tcp::acceptor d_acceptor;
    boost::asio::ip::tcp::socket d_socket;

    void accept()
    {
        d_acceptor.async_accept(d_socket, [this](std::error_code ec) {
            if (!ec) {
                std::make_shared<Session>(std::move(d_socket))->start();
            }

            accept();
        });
    }

  public:
    Server(boost::asio::io_context &context, uint16_t port)
        : d_acceptor(context,
            boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
          d_socket(context)
    {
        accept();
    }
};

#endif