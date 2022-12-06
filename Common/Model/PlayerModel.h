#ifndef CLIENT_PLAYER_MODEL_H
#define CLIENT_PLAYER_MODEL_H
#include <string>



//Clase que contiene todos los datos del jugador(posicion,angulo
//si hace turbo o no,para que lado mira el auto,etc)
//cuya informacion es usada para mostrarla por pantalla
//mientras es actualizada en la fisica del juego.
class PlayerModel {
private:
    int clientId;
    float x;
    float y;
    float angle;
    bool turbo;
    std::string facing;
    int turboRemaining;
    std::string name;
    int goals;
    int assists;

public:
    PlayerModel();
    PlayerModel(int cltId,float xCoord, float yCoord, float ang, bool turbo, std::string facing,
    int turboRem,std::string name,int goals,int assists);

    float getCoordX();
    float getCoordY();
    float getAngle();
    std::string getFacing();
    bool isDoingTurbo();
    int getTurboRemaining();
    int getClientId();
    std::string getName();
    int getGoals();
    int getAssists();

    ~PlayerModel();
};

#endif