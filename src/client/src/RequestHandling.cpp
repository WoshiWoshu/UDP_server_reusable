#include <memory>
#include <string>
#include <iostream>
#include "ClientUDP.hpp"

void preliminary(std::unique_ptr<network::IProtocol> &clientUDP)
{
    std::string msg("OK");

    clientUDP->sendMsg(msg);
    clientUDP->receiveMsg(msg);
    std::cout << "Preliminary From Server: " << msg << std::endl;
}
