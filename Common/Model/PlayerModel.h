#ifndef CLIENT_PLAYER_MODEL_H
#define CLIENT_PLAYER_MODEL_H

class PlayerModel {
private:
    int x;
    int y;
    int angle;
    bool isDoingTurbo;
public:
    PlayerModel();
    PlayerModel(int xCoord, int yCoord, int ang, bool turbo);
    void moveRight();
    void moveLeft();
    int getCoordX();
    int getCoordY();
    int getAngle();

    ~PlayerModel();
};

#endif