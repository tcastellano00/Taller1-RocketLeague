#include <utility>
#include <string>

#include "ActionsLobby.h"

class ActionsLobbyParser {
public:
    static std::unique_ptr<ActionsLobby> getCommand(std::string line);
};
