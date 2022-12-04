#ifndef ACTIONCLIENTJUMP_H
#define ACTIONCLIENTJUMP_H

#include <string>

#include "ActionsClient.h"

class ActionClientJump : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientJump(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientJump() = default;
};

#endif