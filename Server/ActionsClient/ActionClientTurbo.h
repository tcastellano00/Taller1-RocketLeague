#ifndef ACTIONCLIENTTURBO_H
#define ACTIONCLIENTTURBO_H

#include <string>

#include "ActionsClient.h"

class ActionClientTurbo : public ActionsClient {
private:
    int socketId;
public:
    explicit ActionClientTurbo(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientTurbo() = default;
};

#endif