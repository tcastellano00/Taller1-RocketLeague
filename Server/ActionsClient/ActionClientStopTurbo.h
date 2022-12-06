#ifndef ACTIONCLIENTSTOPTURBO_H
#define ACTIONCLIENTSTOPTURBO_H

#include <string>

#include "ActionsClient.h"

/*
Esta clase representa la accion de que un cliente esta
deteniendo el uso del turbo. 
*/
class ActionClientStopTurbo : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientStopTurbo(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientStopTurbo() = default;
};

#endif