#include "ThreadReceiver.h"
#include <iostream>
#include "../Common/Protocol.h"
#include "../Common/LibError.h"
#include "../Common/GameStatusSerializer.h"


ThreadReceiver::ThreadReceiver(Socket& cnct, GameStatusMonitor& newGameStatusMonitor) :
    gameStatusMonitor(newGameStatusMonitor), 
    protocol(cnct) {}

void ThreadReceiver::run() {

    try
    {
        while (!gameStatusMonitor.gameIsClosed()) {
            std::string response = protocol.reciveMessage();
            
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
        gameStatusMonitor.setClose();
    }
}

ThreadReceiver::~ThreadReceiver() {
    this->protocol.close();
    this->join();
}