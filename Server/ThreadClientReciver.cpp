#include <iostream>
#include <utility>
#include <string>

#include "../Common/common_socket.h"
#include "../Common/common_liberror.h"

#include "ThreadClient.h"
#include "ThreadClientReciver.h"

ThreadClientReciver::ThreadClientReciver(Socket &accepter) 
    : accepter(std::move(accepter)) {
        this->isRecibing = true;
    }

void ThreadClientReciver::cleanDeathClients(
    std::list<ThreadClient>& clientThreads) {
    clientThreads.remove_if(
        [](ThreadClient& clientThread) {
            if (not clientThread.isDeath())
                return false;

            clientThread.join();
            return true; 
        });
}

void ThreadClientReciver::run() {
    std::list<ThreadClient> clientThreads;

    while (this->isRecibing)
    {
        try {
            Socket clientConnection = this->accepter.accept();

            if (not this->isRecibing)
                break;

            clientThreads.emplace_back(clientConnection);
            clientThreads.back().start();

            this->cleanDeathClients(clientThreads);
        } catch(const LibError &e) {
            this->isRecibing = false;
        }
    }

    for (auto clientThread = clientThreads.begin(); 
              clientThread != clientThreads.end(); 
              ++clientThread) {
                (*clientThread).stop();
              }
}

void ThreadClientReciver::close_reception() {
    this->isRecibing = false;

    this->accepter.shutdown(2);
    this->accepter.close();
}

ThreadClientReciver::~ThreadClientReciver() {
    this->close_reception();
    this->join();
}
