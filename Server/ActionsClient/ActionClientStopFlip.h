#ifndef ACTIONCLIENTSTOPFLIP_H
#define ACTIONCLIENTSTOPFLIP_H

#include <string>

#include "ActionsClient.h"

class ActionClientStopFlip : public ActionsClient {
private:
    int socketId;
public:
    explicit ActionClientStopFlip(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientStopFlip() = default;
};

#endif