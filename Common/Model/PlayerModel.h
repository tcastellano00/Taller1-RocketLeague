#ifndef CLIENT_PLAYER_MODEL_H
#define CLIENT_PLAYER_MODEL_H

class PlayerModel {
public:
    float x;
    float y;
    float angle;
    bool turbo;

    PlayerModel();
    PlayerModel(float xCoord, float yCoord, float ang, bool turbo);

    float getCoordX();
    float getCoordY();
    float getAngle();
    bool isDoingTurbo();

    ~PlayerModel();
};

#endif