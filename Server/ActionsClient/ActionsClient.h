#ifndef ACTIONSCLIENT_H
#define ACTIONSCLIENT_H

#include <string>
#include <memory>
#include <bits/unique_ptr.h>

class ActionsClient {
protected:
    std::string arguments;
   
public:
    static std::unique_ptr<ActionsClient> get_command_ptr(
        const std::string &name);

    //virtual std::string execute(GameMonitor &game_monitor, ClientConnection& client) = 0;

    ~ActionsClient() = default;
};
#endif