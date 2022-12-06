#ifndef ACTIONCLIENTTURBO_H
#define ACTIONCLIENTTURBO_H

#include <string>

#include "ActionsClient.h"

/*
Esta clase representa la accion de que un cliente esta
queriendo utilizar el turbo. 
*/
class ActionClientTurbo : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientTurbo(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientTurbo() = default;
};

#endif