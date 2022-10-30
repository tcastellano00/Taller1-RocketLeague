#include "common_comando.h"

Comando::Comando(const std::string &tipo_comando,
const std::string &informacion_comando):
    tipo_comando(tipo_comando){}


std::string Comando::obtener_tipo_comando(){
    return tipo_comando;
}

// std::string Comando::obtener_informacion_del_comando(){
//     return informacion_comando;
// }
