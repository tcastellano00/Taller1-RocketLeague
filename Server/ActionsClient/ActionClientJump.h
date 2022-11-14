#ifndef ACTIONCLIENTJUMP_H
#define ACTIONCLIENTJUMP_H

#include <string>

#include "ActionsClient.h"

class ActionClientJump : public ActionsClient {   
public:
    explicit ActionClientJump();

    std::string execute(Physics &physics) override;

    ~ActionClientJump() = default;
};

#endif