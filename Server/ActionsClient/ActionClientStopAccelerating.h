#ifndef ACTIONCLIENTSTOPACCELERATING_H
#define ACTIONCLIENTSTOPACCELERATING_H

#include <string>

#include "ActionsClient.h"

class ActionClientStopAccelerating : public ActionsClient {
private:
    int socketId;
public:
    explicit ActionClientStopAccelerating(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientStopAccelerating() = default;
};

#endif