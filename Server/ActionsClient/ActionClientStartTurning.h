#ifndef ACTIONCLIENTSTARTTURNING_H
#define ACTIONCLIENTSTARTTURNING_H
#include <string>

#include "ActionsClient.h"

class ActionClientStartTurning : public ActionsClient {   
private:
    int socketId;
public:
    explicit ActionClientStartTurning(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientStartTurning() = default;
};

#endif