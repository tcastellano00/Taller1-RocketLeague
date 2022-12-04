#ifndef ACTIONCLIENTSTOPACCELERATING_H
#define ACTIONCLIENTSTOPACCELERATING_H

#include <string>

#include "ActionsClient.h"

class ActionClientStopAccelerating : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientStopAccelerating(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientStopAccelerating() = default;
};

#endif