#ifndef COMMON_DATOS_OPERACION_H
#define COMMON_DATOS_OPERACION_H

#include <inttypes.h>
#include <string>

//Esta clase se encarga de obtener toda la informacion
//acerca de comando que mande el cliente, para despues
//manejar dicha informacion con mas facilidad.
class Comando {
    std::string tipo_comando;
    //std::string informacion_comando;

    public:
    Comando(const std::string &tipo_comando,
    const std::string &informacion_comando);
    
    std::string obtener_tipo_comando();
    //std::string obtener_informacion_del_comando();
};
#endif
