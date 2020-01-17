#include <unistd.h>
#include <string>
#include <cstring>
#include <iostream>
#include <utility>
#include "NewClient.hpp"
#include "SerializationServer.hpp"
#include "Thread.hpp"

//
//Fonction pour vérifier si ID est un nombre
//
static bool isPosNum(const std::string &str)
{
    std::string::const_iterator itStr =
    std::find_if(str.begin(), str.end(), [](const char c) { return !std::isdigit(c); });

    return itStr == str.end();
}

//
//Note : fonction parsing pour récupérer l'ID du client et le msg
//
static std::pair<std::string, std::string> getClientIdMsg(std::string msg)
{
    std::pair<std::string, std::string> clientInfos;
    size_t pos(0);
    std::string token("");
    std::string delimiter (":");

    pos = msg.find(delimiter);
    token = msg.substr(0, pos);
    clientInfos.first = token;
    msg.erase(0, pos + delimiter.length());
    clientInfos.second = msg;
    return (clientInfos);
}

//
//Note for me : need to encapsulate this function inside UDP class
//

static void processClientMsg(const std::shared_ptr<network::IProtocol>
    &serverUDP, std::pair<std::string, std::string> clientInfos)
{
    //
    //clientInfos.first contient ainsi l'ID, je le stock dans client
    //clientInfos.second contient ainsi le message/msg, je le stock dans msg
    //
    int client = 0;
    std::string msg(clientInfos.second);
    int port = 0;

    if (isPosNum(clientInfos.first))
        client = std::stoi(clientInfos.first);
    else
        client = 1;

    //
    //je selectionne le client
    //
    port = serverUDP->selectClient(client);


    //J'envoie ainsi le message à au client/destination en question.
    //Je vérifie bien si le client existe avant d'envoyer
    //Rappel : Si il existe ID : "1" uniquement et j'envoie à ID : "2" celà va échouer, il faut obligatoirement que les clients soient présents pour leur envoyer le message
    //
    if (port != network::FAILURE) {
        serverUDP->sendMsgClient(msg, port);
    }
}

void network::ServerUDP::runServer(void)
{
    std::shared_ptr<network::IProtocol> serverUDP(new network::ServerUDP);
    std::pair<std::string, std::string> clientInfos("", "");
    std::string msg("");
    int client = 0;
    int port = 0;

    //connexion préliminaire entre le serveur et le client
    preliminary(serverUDP);
    while (42) {
        //
        //timer pour attendre un certain temps avant d'annuler receiveMsg(msg).
        //si tu souhaite modifié le temps d'attente, va dans UDP.cpp(line : 46) et modifie : "_timeInterval.tv_sec = X; _timeInterval.tv_usec = X;"
        //X correspondant à la valeur que tu souhaite en seconde, attention les deux prennent la même valeur.
        //
        if (serverUDP->timerReceiveMsg() == network::SUCCESS) {
            //Si le client en question m'envoie bien le message, je le reçois ainsi sous la forme "ID:message"
            //
            //Rappel des règle du Babel : ce message/fichier est déstiné à un autre client pour communiquer
            //
            serverUDP->receiveMsg(msg);
            //
            //je check l'arrivé d'un nouveau client et je repart au début (timerReceiveMsg()) pour attendre l'arrivé du message du nouveau/des clients.
            //
            if (serverUDP->request() == network::SUCCESS) {
                preliminary(serverUDP, msg);
                continue;
            }


            //Tu peux enlever cette affichage si tu le souhaite, il sert principalement à afficher les données circulant entre plusieurs clients
            //Ici j'affiche simplement l'ID du client et son message
            port = serverUDP->getAddr().sin_port;
            client = serverUDP->findIdClient(port);
            std::cout << "From client " << client << ": " << msg << std::endl;
            //

            //je procède au parsing du msg(sous forme ID:message) :
            //je récupère : l'ID(stocké dans "clientInfo.first");
            //je récupère : le message(stocké dans "clientInfo.second");
            //De ce fait, j'ai l'information sur le client de destination (l' "ID");
            //ainsi que le message qui lui ai destiné ("msg");
            //Note : Si le l'ID n'existe pas, c'est à dire que le client n'existe pas, donc le message ne seras pas envoyé
            //Note : Par exemple si j'ai seulement un client, et je met l'ID "2" celà va échouer. Je peux uniquement spécifié l'ID "1" vu qu'il n'existe 1 seul client uniquement.
            //Le nombre maximal de clients qui peuvent se connecter/être en ligne est de 4.
            //Si tu veux peux changer la capacité des clients au totale (genre 10 clients), en allant dans ServerUDP.cpp(ligne 14) et en modifiant ServerUDP (le constructeur)
            clientInfos = getClientIdMsg(msg);
            //
            //Ici je check si un de clients veut se terminer, si c'est le cas je lui renvoie le message "QUIT" puis je le déconnecte/l'enlève de ma liste
            //
            if (clientInfos.second == "QUIT") {
                serverUDP->sendMsg(clientInfos.second);
                serverUDP->disconnectClient(client);
            }
        }
        //
        //J'envoie le message reçus au client en question
        //
        processClientMsg(serverUDP, clientInfos);
    }
}
