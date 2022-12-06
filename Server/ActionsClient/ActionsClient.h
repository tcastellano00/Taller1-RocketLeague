#ifndef ACTIONSCLIENT_H
#define ACTIONSCLIENT_H

#include <string>
#include <memory>
#include <bits/shared_ptr.h>

#include "../Physics/Physics.h"

class ActionsClient {
protected:
    std::string arguments;
    bool skipReplay = false;
   
public:
    static std::shared_ptr<ActionsClient> get_command_ptr(
        const std::string &name, int cltId);

    virtual std::string execute(Physics &physics) = 0;

    bool getSkipReplay();

    ~ActionsClient() = default;
};
#endif