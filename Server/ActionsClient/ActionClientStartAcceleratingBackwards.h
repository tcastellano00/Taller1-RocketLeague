#ifndef ACTIONCLIENTSTARTACCELERATINGBACKWARDS_H
#define ACTIONCLIENTSTARTACCELERATINGBACKWARDS_H

#include <string>

#include "ActionsClient.h"

/*
Esta clase representa la accion de que un cliente esta
queriendo comenzar a acelerar hacia atras. 
*/
class ActionClientStartAcceleratingBackwards : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientStartAcceleratingBackwards(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientStartAcceleratingBackwards() = default;
};

#endif