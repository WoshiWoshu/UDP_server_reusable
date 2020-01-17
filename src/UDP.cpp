// #include <stdio.h>
// #include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "UDP.hpp"

int network::UDP::createSocket(void)
{
    int fdSocket = socket(AF_INET, SOCK_DGRAM, 0);

    if (fdSocket < 0) {
        perror("[ERROR] : Socket creation failed ");
        return (FAILURE);
    }
    return (fdSocket);
}

bool network::UDP::bindSocket(void)
{
    struct sockaddr_in addr;
    int returnVal = 0;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    returnVal = bind(_fdSocket, (const struct sockaddr *)&addr, sizeof(addr));
    if (returnVal < 0) {
        perror("[ERROR] : Bind failed ");
        return (FAILURE);
    }
    return (SUCCESS);
}

bool network::UDP::timerReceiveMsg(void)
{
    int returnVal = 0;
    static int once = 0;

    if (once == 0) {
        fcntl(_fdSocket, F_SETFL, O_NONBLOCK);
        once++;
    }
    FD_ZERO(&_fdRead);
    FD_SET(_fdSocket, &_fdRead);
    //tu peux modifier les deux lignes en dessous, attention il faut qu'il prennent les même valeur.
    //ici j'ai par exemple décidé qu'il y aurais 60 secondes d'attentes maximum avant que recvfrom se débloque.
    //Note : les paquets peuvent être perdu si recvfrom se déloque, car du coup le serveur ne recoit rien.
    _timeInterval.tv_sec = 60;
    _timeInterval.tv_usec = 60;
    returnVal = select(_fdSocket + 1, &_fdRead, NULL, NULL, &_timeInterval);
    if (returnVal == 1)
        return (SUCCESS);
    return (FAILURE);
}

bool network::UDP::connectToServer(const std::string &inetAddr)
{
    _addr.sin_family = AF_INET;
    _addr.sin_port = htons(PORT);
    _addr.sin_addr.s_addr = inet_addr(inetAddr.c_str());
    return (SUCCESS);
}

void network::UDP::receiveMsg(std::string &respMsg)
{
    int len = sizeof(_addr);
    int last_i = 0;
    char respMsgTmp[5000];

    bzero(&_addr, sizeof(_addr));
    last_i = recvfrom(_fdSocket, (char *)respMsgTmp,
    sizeof(respMsgTmp), 0, (struct sockaddr *)&_addr, (socklen_t *)&len);
    respMsgTmp[last_i] = '\0';
    respMsg = respMsgTmp;
}

void network::UDP::sendMsg(const std::string &sendMsg)
{
    sendto(_fdSocket, sendMsg.c_str(), strlen(sendMsg.c_str()),
    0, (const struct sockaddr *)&_addr, sizeof(_addr));
}
