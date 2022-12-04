#ifndef ACTIONCLIENTFLIPRIGHT_H
#define ACTIONCLIENTFLIPRIGHT_H

#include <string>

#include "ActionsClient.h"

class ActionClientFlipRight : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientFlipRight(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientFlipRight() = default;
};

#endif