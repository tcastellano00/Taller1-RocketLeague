#include <iostream>
#include <utility>
#include <string>

#include "../Common/Socket.h"
#include "../Common/LibError.h"

#include "ThreadClient.h"
#include "ThreadClientAcceptor.h"
#include "ClientConnection.h"
#include "ThreadClientLobby.h"
#include "GameMonitor.h"

ThreadClientAcceptor::ThreadClientAcceptor(Socket &accepter) 
    : accepter(std::move(accepter)) {
        this->isReceiving = true;
    }

void ThreadClientAcceptor::cleanDeathClients(
    std::list<ThreadClientLobby>& lobbyThreads) {
    /*
    clientThreads.remove_if(
        [](ThreadClientLobby& clientThread) {
            if (not clientThread.isDeath())
                return false;

            clientThread.join();
            return true; 
        }); */
}

void ThreadClientAcceptor::run() {
    std::list<ThreadClientLobby> clientLobbyThreads;
    GameMonitor gameMonitor;

    while (this->isReceiving)
    {
        try {
            Socket clientSocket = this->accepter.accept();

            if (not this->isReceiving)
                break;

            ClientConnection client(clientSocket, "nombrexd");
            clientLobbyThreads.emplace_back(client, gameMonitor);
            clientLobbyThreads.back().start();

            // al monitor hay que agregarle el clientConnection 

            this->cleanDeathClients(clientLobbyThreads);
        } catch(const LibError &e) {
            this->isReceiving = false;
        }
    }

    for (auto clientThread = clientLobbyThreads.begin(); 
              clientThread != clientLobbyThreads.end(); 
              ++clientThread) {
                (*clientThread).stop();
              }
}

void ThreadClientAcceptor::close_reception() {
    this->isReceiving = false;

    this->accepter.shutdown(2);
    this->accepter.close();
}

ThreadClientAcceptor::~ThreadClientAcceptor() {
    this->close_reception();
    this->join();
}
