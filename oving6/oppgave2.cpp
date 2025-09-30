#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;
using namespace boost::asio::ip;

class HttpServer {
private:
  class Connection {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_context &io_context) : socket(io_context) {}
  };

  boost::asio::io_context io_context;
  tcp::endpoint endpoint;
  tcp::acceptor acceptor;

  void handle_request(shared_ptr<Connection> connection) {
    auto buffer = make_shared<boost::asio::streambuf>();

    async_read_until(connection->socket, *buffer, "\r\n\r\n",
                     [this, connection, buffer](const boost::system::error_code &ec, size_t) {
                       if (!ec) {
                         istream request_stream(buffer.get());
                         string request_line;
                         getline(request_stream, request_line);

                         if (!request_line.empty() && request_line.back() == '\r')
                           request_line.pop_back();

                         cout << "Received: " << request_line << endl;

                         string response;
                         if (request_line.find("GET / ") == 0) {
                           response =
                               "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nDette er hovedsiden";
                         } else if (request_line.find("GET /en_side ") == 0) {
                           response =
                               "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nDette er en side";
                         } else {
                           response =
                               "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\n404 Not Found";
                         }

                         auto write_buffer = make_shared<string>(response);
                         async_write(connection->socket, boost::asio::buffer(*write_buffer),
                                     [connection, write_buffer](const boost::system::error_code &ec, size_t) {
                                       connection->socket.shutdown(tcp::socket::shutdown_both);
                                     });
                       }
                     });
  }

  void accept() {
    auto connection = make_shared<Connection>(io_context);

    acceptor.async_accept(connection->socket,
                          [this, connection](const boost::system::error_code &ec) {
                            accept(); // keep listening
                            if (!ec)
                              handle_request(connection);
                          });
  }

public:
  HttpServer() : endpoint(tcp::v4(), 8080), acceptor(io_context, endpoint) {}

  void start() {
    accept();
    cout << "HTTP server running at http://localhost:8080/" << endl;
    io_context.run();
  }
};

int main() {
  HttpServer server;
  server.start();
}
