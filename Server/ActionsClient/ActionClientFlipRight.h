#ifndef ACTIONCLIENTFLIPRIGHT_H
#define ACTIONCLIENTFLIPRIGHT_H

#include <string>

#include "ActionsClient.h"

class ActionClientFlipRight : public ActionsClient {
private:
    int socketId;
public:
    explicit ActionClientFlipRight(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientFlipRight() = default;
};

#endif