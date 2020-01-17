#include <unistd.h>
#include <cstring>
#include <fstream>
#include <iostream>

#include "UiUtility.hpp"
#include "SerializationClient.hpp"
#include "RequestHandling.hpp"

static void processServerMsg(const std::unique_ptr<network::IProtocol> &clientUDP)
{
    std::string msg("");
    std::string client("");

    //
    //Entrée manuelle temporaire:
    //Ici tu dois sélectionner un client, ça peut être toi même où un autre client.
    //Attention il faut obligatoirement que les clients soient en ligne/existe pour sélectionner leur ID.
    //l'ID peut prendre comme valeur {1, 2, 3 ou 4}.
    //Si par exemple il existe 2 client connecté, tu peux spécifié ici ID : "1" (cette à dire toi même) ou ID : "2" (pour l'autre client connecté)
    //Ensuite tu dois indiqué le fichier/message que tu lui souhaite envoyer
    //Ce doit être un fichier audio, attention à bien indiquer le chemin (absolue ou à partir du dossier).
    //j'ai ici mis quelques fichier audio dans le dossier pour que tu teste.
    //
    //Par la suite il faudras que l'adapte à ton babel, donc changer les 5 lignes juste en bas
    //
    std::cout << "Enter a client ID to send a files to: ";
    std::getline(std::cin, client);
    std::cout << "Enter the file: ";
    std::getline(std::cin, msg);
    msg = client + ":" + msg;

    //
    //j'envoie ensuite le message (sous forme : ID:msg)
    //
    //à l'arriver le serveur le parsera
    //
    clientUDP->sendMsg(msg);
}

//
//N'utilise cette fonction que si tu as besoin de récupérer le contenu de ton fichier sous forme de texte
//


//
//Note for me : need to encapsulate this function inside UDP class
//
//Fonction pour récupérer le contenue du fichier reçus
//
std::string getFileContent(const std::string msg)
{
    std::ifstream file;
    std::string line("");
    std::string fileContent("");

    file.open(msg);
    if (file) {
        line.clear();
        while (std::getline(file, line)) {
            fileContent += line;
        }
    } else {
        std::cerr << "[ERROR] : Files non-existent or corrupted" << std::endl;
        fileContent.clear();
    }
    file.close();
    return fileContent;
}

void network::ClientUDP::runClient(const std::string &inetAddr)
{
    std::unique_ptr<network::IProtocol>
    clientUDP(new network::ClientUDP(inetAddr));
    std::string msg("");
    std::string fileContent("");

    //connexion préliminaire entre le serveur et le client
    preliminary(clientUDP);
    while (strcmp(msg.c_str(), "QUIT") != 0) {
        //
        //J'envoie le message
        //
        processServerMsg(clientUDP);
        //
        //timer pour attendre un certain temps avant d'annuler receiveMsg(msg).
        //si tu souhaite modifié le temps d'attente, va dans UDP.cpp(line : 46) et modifie : "_timeInterval.tv_sec = X; _timeInterval.tv_usec = X;"
        //X correspondant à la valeur que tu souhaite en seconde, attention les deux prennent la même valeur.
        //
        if (clientUDP->timerReceiveMsg() == network::SUCCESS) {
            //
            //Je reçois le fichier audio du client en question
            //ou de moi même (dans le cas ou je décide de me l'auto envoyé : client 1 -> server -> client 1)
            //
            clientUDP->receiveMsg(msg);


            //N'utilise cette fonction en juste en bas que si tu as besoin de récupérer le contenu de ton fichier sous forme de texte
            //tu peux la commenter
            fileContent = getFileContent(msg);

            //
            //une fois que tu à récupérer le fichier audio/msg du client en question ou de "toi même" (auto envoie), tu peux passer le "msg" (fichier audio) à ta fonction de PortAudio qui va s'occuper de l'ouvrir de le lire.

            //
            //Tu dois appelé tes fonctions port audio juste en bas (avant mon "if (fileContent.empty())")
            //


            //
            //Ici je check si le contenu est vide ou le fichier n'existe pas
            //
            if (fileContent.empty())
                fileContent = "NON_EXISTANT";

            //
            //J'affiche simplement le nom du fichier et le contenue provenant du client en question qui me l'as envoyé.
            //Tu peux l'enlevé si tu le désire, c'est juste un affichage
            //

            std::cout << "From Server, successfully received : " << msg << std::endl; //" , File Content: " //<< //fileContent << std::endl;

        }
    }
}
