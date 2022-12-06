#ifndef COMMON_GAMESTATUSSERIALIZER_H
#define COMMON_GAMESTATUSSERIALIZER_H

#include <string>
#include "GameStatus.h"

/*
Esta clase se utiliza para serializar o deserializar un GameStatus.
Puede tomar una GameStatus y convertirlo a string o tomar un string y
devolverte un GameStatus
*/
class GameStatusSerializer {

public:
    explicit GameStatusSerializer();
    
    /*
    Toma un gameStatus y lo convierte a un string
    */
    std::string serialize(GameStatus gameStatus);

    /*
    Toma un string y devuelve un GameStatus.
    */
    GameStatus deserialize(std::string gameStatusString);

    ~GameStatusSerializer() = default;
};

#endif