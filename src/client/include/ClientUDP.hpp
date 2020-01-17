#pragma once

#include "UDP.hpp"

namespace network {

    class ClientUDP : public network::UDP {
    public:
        explicit ClientUDP(const std::string &inetAddr);
        inline ~ClientUDP() { this->UDP::~UDP(); }
    public:
        static void runClient(const std::string &inetAddr);
    public:
        bool request(void) final { return (SUCCESS); };
        int findIdClient(const int &value)
        const final { (void)value; return (SUCCESS); };
        int selectClient(int client)
        const final { (void)client; return (SUCCESS); };
        void disconnectClient(int client) final { (void)client; };
        using network::UDP::createSocket;
        using network::UDP::sendMsg;
        using network::UDP::sendMsgClient;
        using network::UDP::receiveMsg;
        using network::UDP::connectToServer;
        using network::UDP::getAddr;
    };

}
