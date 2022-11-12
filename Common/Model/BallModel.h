#ifndef CLIENT_BALL_MODEL_H
#define CLIENT_BALL_MODEL_H

class BallModel {
private:
    int x;
    int y;
    int angle;

public:
    BallModel();
    BallModel(int xCoord, int yCoord, int ang);
    //void moveRight();
    //void moveLeft();
    int getCoordX();
    int getCoordY();
    int getAngle();

    ~BallModel();
};

#endif