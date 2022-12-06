#include "../GameStatusMonitor.h"

/*
Esta clase se encarga de lanzar el game statistics en QT
*/
class GameStatistics {
    GameStatusMonitor& gameStatusMonitor;

    /* Devuelve true si el cliente quiere volver al lobby */
    bool initGameStatisticsForms();

public:
    GameStatistics(GameStatusMonitor& gameStatusMonitor);

    /* Devuelve true si el cliente quiere volver al lobby */
    bool start();
};