#ifndef ACTIONCLIENTSTARTACCELERATINGBACKWARDS_H
#define ACTIONCLIENTSTARTACCELERATINGBACKWARDS_H

#include <string>

#include "ActionsClient.h"

class ActionClientStartAcceleratingBackwards : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientStartAcceleratingBackwards(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientStartAcceleratingBackwards() = default;
};

#endif