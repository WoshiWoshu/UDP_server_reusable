#pragma once
// 
// #include <vector>
// #include <memory>
// #include <string>
// #include <thread>
// #include "SerializationServer.hpp"
// #include "ServerUDP.hpp"
//
// class Thread {
// public:
//     inline explicit Thread() : _serverUDP(nullptr), _game() {}
//     void handleGames(std::shared_ptr<network::IProtocol> &serverUDP,
//     std::vector<ThunderForce> &game, std::string msg);
// private:
//     void runThread(int client, std::string msg);
//     std::shared_ptr<network::IProtocol> _serverUDP;
//     std::vector<ThunderForce> _game;
// };
