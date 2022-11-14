#ifndef COMMON_GAMESTATUSSERIALIZER_H
#define COMMON_GAMESTATUSSERIALIZER_H

#include <string>
#include "GameStatus.h"

class GameStatusSerializer {

public:
    explicit GameStatusSerializer();

    std::string serialize(GameStatus gameStatus);

    GameStatus deserialize(std::string gameStatusString);

    ~GameStatusSerializer() = default;
};

#endif