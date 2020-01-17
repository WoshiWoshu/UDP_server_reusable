// #include <unistd.h>
// #include <cstring>
// #include <vector>
// #include "../include/sfml.hpp"
// #include "ThunderForce.hpp"
//
// void refreshData(SFML_lib &lib, std::vector<ThunderForce::DataEntity_s> entities)
// {
//
//     int j = 0;
//     int filled = 0;
//     if (lib.graph_vect.size() == 0) {
//         Graph_obj tmp(entities[0].ID, entities[0].Entity, entities[0].XPos, entities[0].YPos);
//         lib.graph_vect.push_back(tmp);
//     }
//     while (j < lib.graph_vect.size()) {
//         lib.graph_vect[j].status = 0;
//         j++;
//     }
//     for (int i = 0; i < entities.size(); i++) {
//         j = 0;
//         while (j < lib.graph_vect.size() && filled == 0) {
//             if (lib.graph_vect[j].ID == entities[i].ID) {
//                 lib.graph_vect[j].x = entities[i].XPos;
//                 lib.graph_vect[j].y = entities[i].YPos;
//                 lib.graph_vect[j].status = 1;
//                 filled = 1;
//             }
//             if (i > lib.graph_vect.size()-1 && filled == 0) {
//                 Graph_obj tmp(entities[i].ID, entities[i].Entity, entities[i].XPos, entities[i].YPos);
//                 lib.graph_vect.push_back(tmp);
//                 lib.graph_vect[j].status = 1;
//                 filled = 1;
//             }
//             j++;
//         }
//         filled = 0;
//     }
// }
//
// std::vector<std::vector<unsigned char>> get_input(unsigned char input)
// {
//     std::vector<std::vector<unsigned char>> vec_big;
//     std::vector<unsigned char> vec_mini;
//     vec_mini.push_back(input);
//     vec_big.push_back(vec_mini);
//     return(vec_big);
// }
