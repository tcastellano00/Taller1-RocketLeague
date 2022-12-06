#ifndef ACTIONCLIENTDOGOLDENSHOT_H
#define ACTIONCLIENTDOGOLDENSHOT_H

#include <string>

#include "ActionsClient.h"

/*
Esta clase representa la accion de que un cliente esta
queriendo hacer un golden shot 
*/
class ActionClientDoGoldenShot : public ActionsClient {
private:
    int clientId;
public:
    explicit ActionClientDoGoldenShot(int cltId);

    std::string execute(Physics &physics) override;

    ~ActionClientDoGoldenShot() = default;
};

#endif