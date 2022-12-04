#ifndef ACTIONCLIENTSTOPTURBO_H
#define ACTIONCLIENTSTOPTURBO_H

#include <string>

#include "ActionsClient.h"

class ActionClientStopTurbo : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientStopTurbo(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientStopTurbo() = default;
};

#endif