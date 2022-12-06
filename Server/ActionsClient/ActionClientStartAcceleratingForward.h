#ifndef ACTIONCLIENTSTARTACCELERATINGFORWARD_H
#define ACTIONCLIENTSTARTACCELERATINGFORWARD_H
#include <string>

#include "ActionsClient.h"

/*
Esta clase representa la accion de que un cliente esta
queriendo comenzar a acelerar hacia delante. 
*/
class ActionClientStartAcceleratingForward : public ActionsClient {   
private:
    int clientId;
public:
    explicit ActionClientStartAcceleratingForward(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientStartAcceleratingForward() = default;
};

#endif
