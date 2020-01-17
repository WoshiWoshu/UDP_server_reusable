// #include <unistd.h>
// #include <string>
// #include <cstring>
// #include <memory>
// #include <iostream>
// #include <algorithm>
// #include <iterator>
// #include <vector>
// #include <array>
// #include "ThunderForce.hpp"
//
// std::vector<std::vector<unsigned char>> parseClientResp(std::string &msg)
// {
//     std::string delimiterA = ";";
//     size_t pos = 0;
//     std::string tokenS;
//     std::vector<std::vector<unsigned char>> allInputs;
//     std::vector<unsigned char> inputs;
//
//     while ((pos = msg.find(delimiterA)) != std::string::npos) {
//         tokenS = msg.substr(0, pos);
//         msg.erase(0, pos + delimiterA.length());
//         for (int i = 0; i < tokenS.size(); i++)
//             inputs.push_back(tokenS[i]);
//         allInputs.push_back(inputs);
//     }
//     return allInputs;
// }
//
// void processMsgClient(ThunderForce &game,
//     std::vector<ThunderForce::DataEntity_s> entities, std::string &msg)
// {
//     entities = game.retriveDataEntity();
//     msg.clear();
//     for (auto &i : entities) {
//         msg += std::to_string((int)i.Entity);
//         msg += ",";
//         msg += std::to_string(i.ID);
//         msg += ",";
//         msg += std::to_string(i.XPos);
//         msg += ",";
//         msg += std::to_string(i.YPos);
//         msg += ",";
//         msg += ";";
//     }
// }
