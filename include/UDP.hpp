#pragma once

#include <unistd.h>
#include <string>
#include "IProtocol.hpp"

namespace network {

    static const int PORT = 8080;
    static const bool SUCCESS = true;
    static const bool FAILURE = false;

    class UDP : public IProtocol {
    public:
        explicit UDP(const std::string &udp);
        UDP(const std::string &udp, const std::string &inetAddr);
        inline ~UDP() { close(_fdSocket); }
    protected:
        void sendMsg(const std::string &sendMsg) final;
        void sendMsgClient(const std::string &sendMsg, int port) override
        { (void)sendMsg; (void)port; };
        bool timerReceiveMsg(void) final;
        void receiveMsg(std::string &respMsg) final;
        bool request(void) override { return (SUCCESS); };
        int createSocket(void) final;
        bool connectToServer(const std::string &inetAddr) final;
        bool bindSocket(void) final;
        struct sockaddr_in getAddr(void) const final { return _addr; }
        int findIdClient(const int &value)
        const override { (void) value; return (SUCCESS); };
        int selectClient(int client)
        const override { (void)client; return (SUCCESS); };
        void disconnectClient(int client) override { (void)client; };
    protected:
        int _fdSocket;
        struct sockaddr_in _addr;
        fd_set _fdRead;
        struct timeval _timeInterval;
    };

}
