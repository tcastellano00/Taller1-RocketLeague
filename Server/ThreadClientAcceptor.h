#ifndef SERVER_THREAD_CLIENT_ACCEPTOR_H
#define SERVER_THREAD_CLIENT_RECIVER_H

#include <list>
#include <atomic>

#include "../Common/Thread.h"
#include "../Common/Socket.h"
#include "ThreadClient.h"

/*  Esta clase implementa la logica de un
    hilo que acepta clientes nuevos.
*/
class ThreadClientAcceptor : public Thread {
private:
    Socket accepter;
    std::atomic<bool> isRecibing;

    /*  Borra y joinea todos los hilos "vivos"
        que tienen un cliente que cerro su socket
    */
    void cleanDeathClients(
        std::list<ThreadClient>& clientThreads);
    
protected:
    void run() override;

public:
    explicit ThreadClientAcceptor(Socket &accepter);
    ~ThreadClientAcceptor();

    /*  Deja de aceptar nuevos clientes.
    */
    void close_reception();

    ThreadClientAcceptor(const ThreadClientAcceptor&) = delete;
    ThreadClientAcceptor& operator=(const ThreadClientAcceptor&) = delete;
};

#endif
