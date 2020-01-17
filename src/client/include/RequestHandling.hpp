#pragma once

#include <memory>
#include "ClientUDP.hpp"

extern void preliminary(std::unique_ptr<network::IProtocol> &clientUDP);
