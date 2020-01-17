#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

namespace network {

    class IProtocol {
    public:
        virtual ~IProtocol() = default;
    public:
        virtual void sendMsg(const std::string &sendMsg) = 0;
        virtual void sendMsgClient(const std::string &sendMsg, int port) = 0;
        virtual void receiveMsg(std::string &respMsg) = 0;
        virtual bool timerReceiveMsg(void) = 0;
        virtual bool request(void) = 0;
        virtual struct sockaddr_in getAddr(void) const = 0;
        virtual int createSocket(void) = 0;
        virtual bool connectToServer(const std::string &inetAddr) = 0;
        virtual bool bindSocket(void) = 0;
        virtual int findIdClient(const int &value) const = 0;
        virtual int selectClient(int client) const = 0;
        virtual void disconnectClient(int client) = 0;
    };

}
