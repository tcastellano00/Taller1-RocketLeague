#ifndef CLIENT_PLAYER_MODEL_H
#define CLIENT_PLAYER_MODEL_H
#include <string>

class PlayerModel {
private:
    int clientId;
    float x;
    float y;
    float angle;
    bool turbo;
    std::string facing;
    int turboRemaining;

public:
    PlayerModel();
    PlayerModel(int cltId,float xCoord, float yCoord, float ang, bool turbo, std::string facing, int turboRem);

    float getCoordX();
    float getCoordY();
    float getAngle();
    std::string getFacing();
    bool isDoingTurbo();
    int getTurboRemaining();
    int getClientId();

    ~PlayerModel();
};

#endif