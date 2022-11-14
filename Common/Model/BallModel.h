#ifndef CLIENT_BALL_MODEL_H
#define CLIENT_BALL_MODEL_H

class BallModel {
private:
    float x;
    float y;
    float angle;

public:
    BallModel();
    BallModel(float xCoord, float yCoord, float ang);
    //void moveRight();
    //void moveLeft();
    float getCoordX();
    float getCoordY();
    float getAngle();

    ~BallModel();
};

#endif