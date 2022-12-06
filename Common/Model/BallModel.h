#ifndef CLIENT_BALL_MODEL_H
#define CLIENT_BALL_MODEL_H
#include <string>



//Clase que contiene todos los datos de la pelota
//cuya informacion es usada para mostrarla por pantalla
//mientras es actualizada en la fisica del juego.
class BallModel {
private:
    float x;
    float y;
    float angle;
    std::string colour;
    bool contactWithBox;


public:
    BallModel();
    BallModel(float xCoord, float yCoord, float ang, std::string colour,bool contactWithBox);
    //void moveRight();
    //void moveLeft();
    float getCoordX();
    float getCoordY();
    float getAngle();
    std::string getColour();

    bool getContactWithBox();

    ~BallModel();
};

#endif