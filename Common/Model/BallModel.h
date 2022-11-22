#ifndef CLIENT_BALL_MODEL_H
#define CLIENT_BALL_MODEL_H
#include <string>

class BallModel {
private:
    float x;
    float y;
    float angle;
    std::string colour;


public:
    BallModel();
    BallModel(float xCoord, float yCoord, float ang, std::string colour);
    //void moveRight();
    //void moveLeft();
    float getCoordX();
    float getCoordY();
    float getAngle();
    std::string getColour();

    ~BallModel();
};

#endif