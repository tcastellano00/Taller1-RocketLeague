#ifndef ACTIONCLIENTLEFT_H
#define ACTIONCLIENTLEFT_H

#include <string>

#include "ActionsClient.h"

class ActionClientLeft : public ActionsClient {
private:
    int socketId;
public:
    explicit ActionClientLeft(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientLeft() = default;
};

#endif