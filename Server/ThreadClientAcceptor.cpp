#include <iostream>
#include <utility>
#include <string>

#include "../Common/Socket.h"
#include "../Common/LibError.h"

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

            ClientConnection client(clientSocket);
            clientLobbyThreads.emplace_back(client, gameMonitor);
            clientLobbyThreads.back().start();

            //this->cleanDeathClients(clientLobbyThreads);
        } catch(const LibError &e) {
            this->isReceiving = false;
        }
    }

    stopClientLobbyThreads(clientLobbyThreads);
    stopGames(gameMonitor);
}

void ThreadClientAcceptor::stopClientLobbyThreads(
    std::list<ThreadClientLobby>& lobbyThreads) {

    // for (auto &lobbyThread : lobbyThreads)
    for (auto lobbyThread = lobbyThreads.begin(); 
              lobbyThread != lobbyThreads.end(); 
              ++lobbyThread) {
        (*lobbyThread).stop();
    }
}

void ThreadClientAcceptor::stopGames(
    GameMonitor& gameMonitor) {
    gameMonitor.finishGames();
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
