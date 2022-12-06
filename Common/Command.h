#ifndef COMMON_DATOS_OPERACION_H
#define COMMON_DATOS_OPERACION_H

#include <inttypes.h>
#include <string>

//Esta clase se encarga de obtener toda la informacion
//acerca de comando que mande el cliente, para despues
//manejar dicha informacion con mas facilidad.
class Command {
    std::string type;

public:
    explicit Command(const std::string &type);
    
    std::string getType();
};
#endif
