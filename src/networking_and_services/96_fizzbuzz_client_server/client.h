#ifndef CLIENT_FIZZBUZZ_96
#define CLIENT_FIZZBUZZ_96
#include <boost/asio.hpp>
#include <ranges>

class Client
{
  private:
    boost::asio::ip::tcp::socket d_socket;

    void send(std::string_view request)
    {
        d_socket.write_some(asio::buffer(request));
    }

    void getResponse()
    {
        std::string reply;
        reply.resize(1024);
        d_socket.read_some(reply, reply.size());
        return reply;
    }

  public:
    Client(boost::asio::io_context &context,
        std::string_view host,
        std::uint16_t port)
        : d_socket(context)
    {
        boost::asio::ip::tcp::resolver resolver(context);
        asio::connect(d_socket, { resolver.resolve(host.data(), port) });
    }

    void run()
    {
        for (auto i : std::views::iota(1, 100)) {
            send(std::to_string(i));
            const auto response = getResponse();
            std::cout << fmt::format("Number {} => {}", i, response);
        }
    }
};


#endif