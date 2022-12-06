#ifndef ACTIONCLIENTFLIPLEFT_H
#define ACTIONCLIENTFLIPLEFT_H

#include <string>

#include "ActionsClient.h"

/*
Esta clase representa la accion de que un cliente esta
queriendo un flip a izquierda
*/
class ActionClientFlipLeft : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientFlipLeft(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientFlipLeft() = default;
};

#endif