#ifndef ACTIONCLIENTDOPURPLESHOT_H
#define ACTIONCLIENTDOPURPLESHOT_H

#include <string>

#include "ActionsClient.h"

class ActionClientDoPurpleShot : public ActionsClient {
private:
    int socketId;
public:
    explicit ActionClientDoPurpleShot(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientDoPurpleShot() = default;
};

#endif