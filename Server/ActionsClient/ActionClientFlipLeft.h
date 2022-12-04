#ifndef ACTIONCLIENTFLIPLEFT_H
#define ACTIONCLIENTFLIPLEFT_H

#include <string>

#include "ActionsClient.h"

class ActionClientFlipLeft : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientFlipLeft(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientFlipLeft() = default;
};

#endif