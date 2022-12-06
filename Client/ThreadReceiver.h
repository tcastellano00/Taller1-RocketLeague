
#include "GameStatusMonitor.h"
#include "../Common/Socket.h"
#include "../Common/Thread.h"
#include "../Common/Protocol.h"

/*
Hilo encargado de recibir la informacion
procesada que ingrese desde el servidor.
*/
class ThreadReceiver: public Thread {
    GameStatusMonitor& gameStatusMonitor;
    Protocol protocol;

public:
    ThreadReceiver(Socket& cnct, GameStatusMonitor& gameStatusMonitor);

    void run() override;
    ~ThreadReceiver();
};
