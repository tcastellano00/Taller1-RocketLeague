#ifndef ACTIONCLIENTDOGOLDENSHOT_H
#define ACTIONCLIENTDOGOLDENSHOT_H

#include <string>

#include "ActionsClient.h"

class ActionClientDoGoldenShot : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientDoGoldenShot(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientDoGoldenShot() = default;
};

#endif