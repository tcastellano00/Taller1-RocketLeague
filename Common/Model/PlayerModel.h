#ifndef CLIENT_PLAYER_MODEL_H
#define CLIENT_PLAYER_MODEL_H

class PlayerModel {
private:
    float x;
    float y;
    float angle;
    bool turbo;

public:
    PlayerModel();
    PlayerModel(float xCoord, float yCoord, float ang, bool turbo);

    float getCoordX();
    float getCoordY();
    float getAngle();
    bool isDoingTurbo();

    ~PlayerModel();
};

#endif