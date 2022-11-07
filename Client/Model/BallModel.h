#ifndef CLIENT_BALL_MODEL_H
#define CLIENT_BALL_MODEL_H
#include "../SDL/Animation.h"

class BallModel {
private:
    int x;
    int y;

public:
    BallModel();
    //void moveRight();
    //void moveLeft();
    int getCoordX();
    int getCoordY();

    ~BallModel();
};

#endif