#ifndef ACTIONCLIENTTURBO_H
#define ACTIONCLIENTTURBO_H

#include <string>

#include "ActionsClient.h"

class ActionClientTurbo : public ActionsClient {   
public:
    explicit ActionClientTurbo();

    std::string execute(Physics &physics) override;

    ~ActionClientTurbo() = default;
};

#endif