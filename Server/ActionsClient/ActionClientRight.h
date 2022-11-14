#ifndef ACTIONCLIENTRIGHT_H
#define ACTIONCLIENTRIGHT_H
#include <string>

#include "ActionsClient.h"

class ActionClientRight : public ActionsClient {   
public:
    explicit ActionClientRight();

    std::string execute(Physics &physics) override;

    ~ActionClientRight() = default;
};

#endif
