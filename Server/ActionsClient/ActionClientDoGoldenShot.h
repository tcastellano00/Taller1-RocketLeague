#ifndef ACTIONCLIENTDOGOLDENSHOT_H
#define ACTIONCLIENTDOGOLDENSHOT_H

#include <string>

#include "ActionsClient.h"

class ActionClientDoGoldenShot : public ActionsClient {
private:
    int socketId;
public:
    explicit ActionClientDoGoldenShot(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientDoGoldenShot() = default;
};

#endif