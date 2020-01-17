#pragma once

#include <memory>
#include "ServerUDP.hpp"
// #include "ThunderForce.hpp"

extern void preliminary(std::shared_ptr<network::IProtocol> &serverUDP);
extern void preliminary(std::shared_ptr<network::IProtocol> &serverUDP,
    std::string &msg);
