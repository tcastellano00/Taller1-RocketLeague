#ifndef ACTIONCLIENTSTARTTURNING_H
#define ACTIONCLIENTSTARTTURNING_H
#include <string>

#include "ActionsClient.h"

class ActionClientStartTurning : public ActionsClient {   
private:
    int clientId;
public:
    explicit ActionClientStartTurning(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientStartTurning() = default;
};

#endif