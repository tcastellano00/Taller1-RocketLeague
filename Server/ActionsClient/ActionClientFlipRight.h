#ifndef ACTIONCLIENTFLIPRIGHT_H
#define ACTIONCLIENTFLIPRIGHT_H

#include <string>

#include "ActionsClient.h"

/*
Esta clase representa la accion de que un cliente esta
queriendo hacer un flip a derecha
*/
class ActionClientFlipRight : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientFlipRight(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientFlipRight() = default;
};

#endif