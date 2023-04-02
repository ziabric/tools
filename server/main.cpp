#include <iostream>
#include <boost/asio.hpp>
#include <string>

using boost::asio::ip::tcp;

int main()
{
    try
    {
        boost::asio::io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 8080)); // прослушиваем порт 80

        while (true) {
            tcp::socket socket(io_service);
            acceptor.accept(socket);

            boost::asio::streambuf request_buf;
            boost::asio::read_until(socket, request_buf, "\r\n\r\n"); // читаем заголовки HTTP-запроса

            std::string response = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\nContent-Type: text/plain\r\n\r\nHello, world!"; // формируем HTTP-ответ
            boost::asio::write(socket, boost::asio::buffer(response)); // отправляем HTTP-ответ
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
