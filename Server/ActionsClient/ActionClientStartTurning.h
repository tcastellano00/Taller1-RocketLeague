#ifndef ACTIONCLIENTSTARTTURNING_H
#define ACTIONCLIENTSTARTTURNING_H
#include <string>

#include "ActionsClient.h"

/*
Esta clase representa la accion de que un cliente esta
queriendo apuntar la trompa del auto hacia el otro lado. 
*/
class ActionClientStartTurning : public ActionsClient {   
private:
    int clientId;
public:
    explicit ActionClientStartTurning(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientStartTurning() = default;
};

#endif