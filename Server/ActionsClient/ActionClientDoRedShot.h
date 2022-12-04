#ifndef ACTIONCLIENTDOREDSHOT_H
#define ACTIONCLIENTDOREDSHOT_H

#include <string>

#include "ActionsClient.h"

class ActionClientDoRedShot : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientDoRedShot(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientDoRedShot() = default;
};

#endif