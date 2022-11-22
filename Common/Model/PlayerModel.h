#ifndef CLIENT_PLAYER_MODEL_H
#define CLIENT_PLAYER_MODEL_H
#include <string>

class PlayerModel {
private:
    float x;
    float y;
    float angle;
    bool turbo;
    std::string facing;

public:
    PlayerModel();
    PlayerModel(float xCoord, float yCoord, float ang, bool turbo, std::string facing);

    float getCoordX();
    float getCoordY();
    float getAngle();
    std::string getFacing();
    bool isDoingTurbo();

    ~PlayerModel();
};

#endif