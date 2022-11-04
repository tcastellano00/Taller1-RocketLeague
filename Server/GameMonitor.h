#include <list>

#include "Game.h"

class GameMonitor {
private:
    std::list<Game> games;

public:
    /*
    * Construye el GameMonitor.
    * */
    explicit GameMonitor();

    /*
    * Libera los recursos.
    * */
    ~GameMonitor();
};
