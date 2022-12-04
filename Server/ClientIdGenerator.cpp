#include "ClientIdGenerator.h"

ClientIdGenerator* ClientIdGenerator::clientIdGenerator = nullptr;

ClientIdGenerator::ClientIdGenerator() {
    this->actualId = 0;
}

ClientIdGenerator* ClientIdGenerator::getInstance() {
    if (clientIdGenerator == nullptr) {
        clientIdGenerator = new ClientIdGenerator();
    }

    return clientIdGenerator;
}

void ClientIdGenerator::reset() {
    getInstance()->actualId = 0;
}

int ClientIdGenerator::getId() {
    getInstance()->actualId += 1;
    return getInstance()->actualId;
}