#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/format.hpp>
#include <boost/thread.hpp>
#include <boost/array.hpp>
#include "udp.hpp"

using namespace boost::asio::ip;



void UDP::udp_setting(std::string IPaddress,int port){
    this->IPaddress=IPaddress;
    this->port=port;
}

void UDP::udp_send(std::string text_sended){
    udp::socket sock(io_service, udp::endpoint(udp::v4(), port));
    sock.send_to
    (
        boost::asio::buffer(text_sended),
        udp::endpoint(address::from_string(IPaddress), port)
    );
}

std::string UDP::udp_recieve(){
    udp::socket sock(io_service, udp::endpoint(udp::v4(), port));
    
    size_t len = sock.receive_from(boost::asio::buffer(recv_buf), endpoint);
    std::cout.write(recv_buf.data(), len);
    std::string result_string=recv_buf.data();
    return result_string;
}
int main()
{
    //繰り返し送信する
    UDP udp;
    int port=1244;
    std::string IPaddress="192.168.0.100";
    udp.udp_setting(IPaddress,port);

    bool flag_send=true;

    for(int i=0; true; i++)
    {
        //1秒待機（送信しすぎないように）
        if(flag_send){
            std::string text_sended=std::to_string(i);
            std::cout<<text_sended<<std::endl;
            udp.udp_send(text_sended);
        }
        else{
            std::string recieve=udp.udp_recieve();
            std::cout<<recieve<<std::endl;
        }


        boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
    }

    return 0;
}