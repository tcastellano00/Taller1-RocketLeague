#ifndef ACTIONCLIENTSTOPTURBO_H
#define ACTIONCLIENTSTOPTURBO_H

#include <string>

#include "ActionsClient.h"

class ActionClientStopTurbo : public ActionsClient {
private:
    int socketId;
public:
    explicit ActionClientStopTurbo(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientStopTurbo() = default;
};

#endif