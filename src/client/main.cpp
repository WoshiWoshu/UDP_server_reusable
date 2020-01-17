#include <unistd.h>
#include <cstring>
#include <iostream>
#include <string>
#include "ClientUDP.hpp"

int main(void)
{
    std::string inetAddr(" ");

    printf("Enter an inetAddr: ");
    std::getline(std::cin, inetAddr);
    network::ClientUDP::runClient(inetAddr);
    return (0);
}
