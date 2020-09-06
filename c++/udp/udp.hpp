#ifndef UDP_hpp
#define UDP_hpp

#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/format.hpp>
#include <boost/thread.hpp>
#include <boost/array.hpp>

using namespace boost::asio::ip;


class UDP{
    public:
        std::string IPaddress;
        int port;
        boost::asio::io_service io_service;

        void udp_setting(std::string IPaddress,int port);
        void udp_send(std::string text_sended);
        std::string udp_recieve();
        boost::array<char, 128> recv_buf;
        udp::endpoint endpoint;
    private:

};

#endif