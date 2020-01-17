// #include "Thread.hpp"
//
// void Thread::runThread(int client, std::string msg)
// {
//     std::vector<ThunderForce::DataEntity_s> entities;
//     int port = 0;
//
//     _game[client - 1].updateData(parseClientResp(msg));
//     processMsgClient(_game[client - 1], entities, msg);
//     port = _serverUDP->selectClient(client);
//     _serverUDP->sendMsgClient(msg, port);
// }
//
// void Thread::handleGames(std::shared_ptr<network::IProtocol> &serverUDP,
// std::vector<ThunderForce> &game, std::string msg)
// {
//     int client = 0;
//
//     _serverUDP = serverUDP;
//     _game = game;
//     client =
//     _serverUDP->findIdClient(_serverUDP->getAddr().sin_port);
//     std::thread bThread(&Thread::runThread, this, client, msg);
//     bThread.join();
//     game = _game;
//     serverUDP = _serverUDP;
// }
