#ifndef ACTIONCLIENTRIGHT_H
#define ACTIONCLIENTRIGHT_H
#include <string>

#include "ActionsClient.h"

class ActionClientRight : public ActionsClient {   
private:
    int socketId;
public:
    explicit ActionClientRight(int sktId);

    std::string execute(Physics &physics) override;

    ~ActionClientRight() = default;
};

#endif
