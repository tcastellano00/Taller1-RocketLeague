#ifndef SERVER_THREAD_CLIENT_H
#define SERVER_THREAD_CLIENT_H

#include <atomic>
#include <string>

#include "common_thread.h"
#include "common_protocol.h"

/*  Esta clase implementa la logica de un
    hilo que "conversa" con un cliente en
    particular.
*/
class ThreadClient : public Thread {
private:
    Protocol protocol;
    
    std::atomic<bool> deathClient;
    std::atomic<bool> talkWithClient;

    /*  Recibe un comando y lo ejecuta */
    std::string recive_and_execute_command();
    
    /*  Envia el resultado del servidor */
    void send_result(std::string const &result);

protected:
    void run() override;

public:
    ThreadClient(Socket& socket);
    ~ThreadClient();
    
    /*  Cierra la "conversacion" con el cliente */
    void stop();

    /*  Devuelve true si el cliente se desconecto,
        sino devuelve false.
    */
    bool isDeath();

    ThreadClient(const ThreadClient&) = delete;
    ThreadClient& operator=(const ThreadClient&) = delete;
};

#endif
