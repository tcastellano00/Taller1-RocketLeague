#include <string>
#include <sstream>

#include "ActionClientFlipLeft.h"

ActionClientFlipLeft::ActionClientFlipLeft(int sktId) {
    // Dejo el comentario acá, pero aplica a todo el código:
    // Por favor usen un identificador del cliente, que no sea el file descriptor
    // del socket. Podría ser un int que tengan en el acceptor y lo van
    // incrementando cada vez que aceptan un client. Sino están rompiendo el
    // encapsulamiento dle socket.
    this->socketId = sktId;
}

std::string ActionClientFlipLeft::execute(
    Physics &physics) {
    physics.flipCarLeft(socketId);
    return "";
}