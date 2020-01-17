#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>
#include "UDP.hpp"

namespace network {

    class ServerUDP : public network::UDP {
    public:
        explicit ServerUDP();
        inline ~ServerUDP() { this->UDP::~UDP(); }
    public:
        static void runServer(void);
    public:
        bool request(void) final;
        int findIdClient(const int &value) const final;
        int selectClient(int client) const final;
        void sendMsgClient(const std::string &sendMsg, int port) final;
        void disconnectClient(int client) final;
        using network::UDP::createSocket;
        using network::UDP::receiveMsg;
        using network::UDP::bindSocket;
        using network::UDP::getAddr;
    private:
        std::set<int> _dataBasePlayers;
        std::map<int, int> _onlinePlayers;
    };

}
