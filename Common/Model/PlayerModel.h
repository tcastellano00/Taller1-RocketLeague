#ifndef CLIENT_PLAYER_MODEL_H
#define CLIENT_PLAYER_MODEL_H

class PlayerModel {
public:
    float x;
    float y;
    float angle;
    bool isDoingTurbo;

    PlayerModel();
    PlayerModel(float xCoord, float yCoord, float ang, bool turbo);
    void moveRight();
    void moveLeft();

    //void setCoordX();

    float getCoordX();
    float getCoordY();
    float getAngle();

    ~PlayerModel();
};

#endif