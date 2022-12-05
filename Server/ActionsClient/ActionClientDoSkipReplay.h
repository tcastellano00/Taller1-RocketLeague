#ifndef ACTIONCLIENTDOSKIPREPLAY_H
#define ACTIONCLIENTDOSKIPREPLAY_H

#include <string>

#include "ActionsClient.h"

class ActionClientDoSkipReplay : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientDoSkipReplay(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientDoSkipReplay() = default;
    
};

#endif