#ifndef CLIENT_BALL_MODEL_H
#define CLIENT_BALL_MODEL_H
#include "../SDL/Animation.h"

class BallModel {
private:
    int x;
    int y;
    int angle;

public:
    BallModel();
    //void moveRight();
    //void moveLeft();
    int getCoordX();
    int getCoordY();
    int getAngle();

    ~BallModel();
};

#endif