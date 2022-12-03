#ifndef ACTIONCLIENTSTARTACCELERATINGBACKWARDS_H
#define ACTIONCLIENTSTARTACCELERATINGBACKWARDS_H

#include <string>

#include "ActionsClient.h"

class ActionClientStartAcceleratingBackwards : public ActionsClient {
private:
    int socketId;
public:
    explicit ActionClientStartAcceleratingBackwards(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientStartAcceleratingBackwards() = default;
};

#endif