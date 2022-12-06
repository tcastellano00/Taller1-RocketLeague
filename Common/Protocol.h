#ifndef COMMON_PROTOCOL_H
#define COMMON_PROTOCOL_H

#include <string>
#include "Socket.h"

/* 
Esta clase implementa la funcionalidad base de un protocolo de comunicacion.
El protocolo es de tipo texto, y los mensajes se separan por un doble salto de linea. Una vez dentro
de la partida, mediante este mensaje se envian varios parametros, los cuales se encuentran separados por
un espacio. El manejo de este mensaje se deriva en la clase GameStatusSerializer.
*/
class Protocol {
private:
    Socket& socket;
    bool closedSocket;
    
    /*  Cierra el socket */
    void closeSocket();
    std::string previousHalfMessage;

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
