// #include <unistd.h>
// #include <cstring>
// #include <string>
// #include <iostream>
// #include <memory>
// #include <vector>
// #include "ThunderForce.hpp"
// #include "ClientUDP.hpp"
//
// std::vector<ThunderForce::DataEntity_s> parseClientResp(std::string &msg)
// {
//     std::string delimiterA = ";";
//     std::string delimiterB = ",";
//     size_t pos = 0;
//     size_t browse = 0;
//     std::string tokenS;
//     std::string token;
//     std::vector<ThunderForce::DataEntity_s> entities;
//     ThunderForce::DataEntity_t dataEntity;
//
//     while ((pos = msg.find(delimiterA)) != std::string::npos) {
//         tokenS = msg.substr(0, pos);
//         msg.erase(0, pos + delimiterA.length());
//         browse = 0;
//         while ((pos = tokenS.find(delimiterB)) != std::string::npos) {
//             token = tokenS.substr(0, pos);
//             tokenS.erase(0, pos + delimiterB.length());
//             if (browse == 0)
//                 dataEntity.Entity = (ThunderForce::ENTITY)std::stoi(token);
//             browse == 1 ? dataEntity.ID = std::stoi(token) : 0;
//             browse == 2 ? dataEntity.XPos = std::stoi(token) : 0;
//             browse == 3 ? dataEntity.YPos = std::stoi(token) : 0;
//             browse++;
//         }
//         entities.push_back(dataEntity);
//     }
//     return entities;
// }
