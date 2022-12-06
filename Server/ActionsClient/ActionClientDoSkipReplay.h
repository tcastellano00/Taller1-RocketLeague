#ifndef ACTIONCLIENTDOSKIPREPLAY_H
#define ACTIONCLIENTDOSKIPREPLAY_H

#include <string>

#include "ActionsClient.h"

/*
Esta clase representa la accion de que un cliente esta
queriendo saltar la repetición
*/
class ActionClientDoSkipReplay : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientDoSkipReplay(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientDoSkipReplay() = default;
    
};

#endif