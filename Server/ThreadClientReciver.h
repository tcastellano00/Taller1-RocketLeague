#ifndef SERVER_THREAD_CLIENT_RECIVER_H
#define SERVER_THREAD_CLIENT_RECIVER_H

#include <list>
#include <atomic>

#include "../Common/common_thread.h"
#include "../Common/common_socket.h"
#include "ThreadClient.h"

/*  Esta clase implementa la logica de un
    hilo que acepta clientes nuevos.
*/
class ThreadClientReciver : public Thread {
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
    explicit ThreadClientReciver(Socket &accepter);
    ~ThreadClientReciver();

    /*  Deja de aceptar nuevos clientes.
    */
    void close_reception();

    ThreadClientReciver(const ThreadClientReciver&) = delete;
    ThreadClientReciver& operator=(const ThreadClientReciver&) = delete;
};

#endif
