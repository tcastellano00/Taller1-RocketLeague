#include <utility>
#include "LobbyCommand.h"
#include <string>

class LobbyParser {
public:
    static std::unique_ptr<LobbyCommand> getCommand(std::string line);
};
