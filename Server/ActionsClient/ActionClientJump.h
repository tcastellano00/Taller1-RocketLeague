#ifndef ACTIONCLIENTJUMP_H
#define ACTIONCLIENTJUMP_H

#include <string>

#include "ActionsClient.h"

class ActionClientJump : public ActionsClient {
private:
    int socketId;
public:
    explicit ActionClientJump(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientJump() = default;
};

#endif