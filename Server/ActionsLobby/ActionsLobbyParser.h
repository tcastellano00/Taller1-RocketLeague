#include <utility>
#include <string>

#include "ActionsLobby.h"

/*
Esta clase es utilizada para que a partir de una linea de comando
de tipo string el programa pueda determinar que tipo de comando se
quiere ejecutar sobre el lobby y con que argumentos.
*/
class ActionsLobbyParser {
public:
    static std::unique_ptr<ActionsLobby> getCommand(std::string line);
};
