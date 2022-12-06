#ifndef ACTIONCLIENTSTOPFLIP_H
#define ACTIONCLIENTSTOPFLIP_H

#include <string>

#include "ActionsClient.h"

/*
Esta clase representa la accion de que un cliente esta
queriendo detener el flip. 
*/
class ActionClientStopFlip : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientStopFlip(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientStopFlip() = default;
};

#endif