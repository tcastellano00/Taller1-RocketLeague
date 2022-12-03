#ifndef ACTIONCLIENTSTARTACCELERATINGFORWARD_H
#define ACTIONCLIENTSTARTACCELERATINGFORWARD_H
#include <string>

#include "ActionsClient.h"

class ActionClientStartAcceleratingForward : public ActionsClient {   
private:
    int socketId;
public:
    explicit ActionClientStartAcceleratingForward(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientStartAcceleratingForward() = default;
};

#endif
