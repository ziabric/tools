#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace boost::property_tree;
using namespace boost::asio::ip;

int main()
{
    boost::asio::io_service io_service;
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 8080));

    while (true)
    {
        tcp::socket socket(io_service);
        acceptor.accept(socket);

        boost::asio::streambuf buffer;
        boost::asio::read_until(socket, buffer, "\r\n");

        std::istream input_stream(&buffer);
        std::string request_method, http_version;

        std::string req;
        std::getline(input_stream, req, '\0');
        std::cout<<req<<std::endl;

        std::getline(input_stream, request_method, ' ');
        input_stream.ignore();
        std::getline(input_stream, http_version, '\r');


        std::string response_body = "Hello, World";
        std::string response_header ="HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nConnection: close\r\n\r\n";

        boost::asio::write(socket, boost::asio::buffer(response_header));
        boost::asio::write(socket, boost::asio::buffer(response_body));
    }

    return 0;
}
