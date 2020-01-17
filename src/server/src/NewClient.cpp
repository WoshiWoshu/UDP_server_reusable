#include <unistd.h>
#include <string>
#include <cstring>
#include <iostream>
#include <memory>
#include "SerializationServer.hpp"
#include "ServerUDP.hpp"


void preliminary(std::shared_ptr<network::IProtocol> &serverUDP)
{
    std::string msg("");
    int client = 0;
    int port = 0;

    serverUDP->receiveMsg(msg);
    serverUDP->request();


    port = serverUDP->getAddr().sin_port;
    client = serverUDP->findIdClient(port);
    std::cout << "Preliminary, New Client "
    << client << " :" << msg << std::endl;


    msg = "OK";
    serverUDP->sendMsg(msg);
}

void preliminary(std::shared_ptr<network::IProtocol> &serverUDP,
    std::string &msg)
{
    int client = 0;
    int port = 0;


    port = serverUDP->getAddr().sin_port;
    client = serverUDP->findIdClient(port);
    std::cout << "Preliminary, New Client "
    << client << " :" << msg << std::endl;


    msg = "OK";
    serverUDP->sendMsg(msg);
}
