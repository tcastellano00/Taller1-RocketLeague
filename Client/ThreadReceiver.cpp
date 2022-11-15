#include "ThreadReceiver.h"
#include <iostream>
#include "../Common/Protocol.h"
#include "../Common/LibError.h"
#include "../Common/GameStatusSerializer.h"


ThreadReceiver::ThreadReceiver(Socket& cnct, GameStatusMonitor& newGameStatusMonitor) :
    gameStatusMonitor(newGameStatusMonitor), 
    protocol(cnct) {}

void ThreadReceiver::run() {
    std::cout << "Im running receiver thread" << std::endl;

    try
    {
        while (!gameStatusMonitor.gameIsClosed()) {
            std::string response = protocol.reciveMessage();
            //std::cout << response << std::endl;
            if (response == "close") {
                gameStatusMonitor.setClose();
                break;
            }
            GameStatusSerializer serializer;
            GameStatus newGameStatus = serializer.deserialize(response);

            gameStatusMonitor.statusUpdate(newGameStatus);
            
        }
    }
    catch(const LibError& e)
    {
        std::cout << "Se corto la conexcion en el reciver" << std::endl;
        gameStatusMonitor.setClose();
    }
}

ThreadReceiver::~ThreadReceiver() {
    std::cout << "Cerramos receiver" << std::endl;
    this->protocol.close();
    this->join();
}