#include "../Common/Thread.h"
#include "../Common/BlockingQueue.h"
#include "../Common/Command.h"
#include "../Common/Socket.h"
#include "GameStatusMonitor.h"

/*
Hilo encargado de enviar la informacion (popeando
desde la cola de eventos) que ingrese el cliente al servidor.
*/
class ThreadSender: public Thread {
private:
    BlockingQueue<Command>& queue;
    Socket& connection;
    GameStatusMonitor& gameStatusMonitor;
    
public:
    void run() override;
    ThreadSender(
        BlockingQueue<Command>& newQueue, 
        Socket& cnct, 
        GameStatusMonitor& gameStatusMonitor);
    ~ThreadSender();
};
