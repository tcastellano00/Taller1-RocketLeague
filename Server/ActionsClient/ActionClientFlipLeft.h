#ifndef ACTIONCLIENTFLIPLEFT_H
#define ACTIONCLIENTFLIPLEFT_H

#include <string>

#include "ActionsClient.h"

class ActionClientFlipLeft : public ActionsClient {
private:
    int socketId;
public:
    explicit ActionClientFlipLeft(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientFlipLeft() = default;
};

#endif