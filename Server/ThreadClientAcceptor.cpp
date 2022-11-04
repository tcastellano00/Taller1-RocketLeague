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
    std::list<ThreadClientLobby>& clientThreads) {
    clientThreads.remove_if(
        [](ThreadClient& clientThread) {
            if (not clientThread.isDeath())
                return false;

            clientThread.join();
            return true; 
        });
}

void ThreadClientAcceptor::run() {
    std::list<ThreadClientLobby> clientThreads;
    GameMonitor gameMonitor;

    while (this->isReceiving)
    {
        try {
            Socket clientConnection = this->accepter.accept();

            if (not this->isReceiving)
                break;

            //recievers
            /*clientThreads.emplace_back(clientConnection);
            clientThreads.back().start();*/

            ClientConnection client(clientConnection, "nombrexd");
            clientThreads.emplace_back(client, gameMonitor);
            clientThreads.back().start();

            // al monitor hay que agregarle el clientConnection 

            this->cleanDeathClients(clientThreads);
        } catch(const LibError &e) {
            this->isReceiving = false;
        }
    }

    for (auto clientThread = clientThreads.begin(); 
              clientThread != clientThreads.end(); 
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
