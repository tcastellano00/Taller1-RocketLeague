#include "../Common/Socket.h"
#include "GameStatusMonitor.h"

/*
Clase encargada de lanzar todos los hilos
necesarios para el desarollo del programa.
*/
class ThreadLauncher {
public:
    ThreadLauncher();
    void start(Socket& connection,GameStatusMonitor& gameStatusMonitor);
    
};

