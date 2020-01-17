#include <string.h>
#include "UDP.hpp"

network::UDP::UDP(const std::string &udp) : _fdSocket(this->createSocket())
{
    memset(&_addr, 0, sizeof(_addr));
    if (!_fdSocket)
        exit(84);
    if (udp == "server") {
        if (!this->bindSocket())
            exit(84);
    }
}

network::UDP::UDP(const std::string &udp, const std::string &inetAddr) :
    _fdSocket(this->createSocket())
{
    memset(&_addr, 0, sizeof(_addr));
    if (!_fdSocket)
        exit(84);
    if (udp == "client") {
        if (!connectToServer(inetAddr))
            exit(84);
    }
}
