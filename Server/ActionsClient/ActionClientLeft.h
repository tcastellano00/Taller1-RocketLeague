#ifndef ACTIONCLIENTLEFT_H
#define ACTIONCLIENTLEFT_H

#include <string>

#include "ActionsClient.h"

class ActionClientLeft : public ActionsClient {   
public:
    explicit ActionClientLeft();

    std::string execute(Physics &physics) override;

    ~ActionClientLeft() = default;
};

#endif