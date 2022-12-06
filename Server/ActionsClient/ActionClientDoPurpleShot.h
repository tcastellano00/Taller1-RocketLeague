#ifndef ACTIONCLIENTDOPURPLESHOT_H
#define ACTIONCLIENTDOPURPLESHOT_H

#include <string>

#include "ActionsClient.h"

/*
Esta clase representa la accion de que un cliente esta
queriendo hacer un purple shot 
*/
class ActionClientDoPurpleShot : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientDoPurpleShot(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientDoPurpleShot() = default;
};

#endif