#ifndef CLIENT_PLAYER_MODEL_H
#define CLIENT_PLAYER_MODEL_H

class PlayerModel {
private:
    int x;
    int y;
    int angle;
public:
    PlayerModel();
    void moveRight();
    void moveLeft();
    int getCoordX();
    int getCoordY();
    int getAngle();

    ~PlayerModel();
};

#endif