#ifndef ACTIONCLIENTDOPURPLESHOT_H
#define ACTIONCLIENTDOPURPLESHOT_H

#include <string>

#include "ActionsClient.h"

class ActionClientDoPurpleShot : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientDoPurpleShot(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientDoPurpleShot() = default;
};

#endif