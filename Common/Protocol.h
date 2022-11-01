#ifndef COMMON_PROTOCOL_H
#define COMMON_PROTOCOL_H

#include <string>
#include "Socket.h"

/*  Esta clase implementa la funcionalidad
    base de un protocolo de comunicacion 
*/
class Protocol {
private:
    Socket socket;
    bool closedSocket;
    
    /*  Cierra el socket */
    void closeSocket();

public:
    /*  Construye el protocolo 
    */
    explicit Protocol(Socket& socket);
    
    /*  Recibe el mensaje que se envio 
        a travez del socket */
    std::string reciveMessage();

    /*  Envia un mensaje a travez del
        socket */
    void sendMessage(const std::string& message);

    /*  Devuelve true si el canal de comunicacion
        esta cerrado
    */
    bool isClosed();

    /*  Cierra el canal de comunicacion
    */
    void close();

    /*
    * Libera los recursos.
    * */
    virtual ~Protocol() = default;
};

#endif
