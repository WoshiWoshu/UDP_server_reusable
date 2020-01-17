#include "ClientUDP.hpp"

network::ClientUDP::ClientUDP(const std::string &inetAddr) :
    network::UDP("client", inetAddr)
{}
