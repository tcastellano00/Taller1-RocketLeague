#ifndef ACTIONCLIENTJUMP_H
#define ACTIONCLIENTJUMP_H

#include <string>

#include "ActionsClient.h"

/*
Esta clase representa la accion de que un cliente esta
queriendo saltar
*/
class ActionClientJump : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientJump(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientJump() = default;
};

#endif