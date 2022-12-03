#ifndef ACTIONCLIENTDOREDSHOT_H
#define ACTIONCLIENTDOREDSHOT_H

#include <string>

#include "ActionsClient.h"

class ActionClientDoRedShot : public ActionsClient {
private:
    int socketId;
public:
    explicit ActionClientDoRedShot(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientDoRedShot() = default;
};

#endif