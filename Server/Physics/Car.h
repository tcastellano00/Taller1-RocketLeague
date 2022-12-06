#ifndef CARPHYSICS_H
#define CARPHYSICS_H

#include "../Box2D/Box2D.h"
//#include "BallPhysics.h"
#include "../../Common/Model/PlayerModel.h"
#include "../../Common/Config/ServerConfig.h"
#include <string>
// class CarPhisics{
//     b2World * &m_world;
    
//     public:
//     CarPhisics(b2World * &m_world);
// };

//Tipo de sensor que posee el auto.
enum SensorStatus {   
    BALLINFRONTSENSOR,
    BALLINBOTTOMSENSOR,
    BALLINBACKSENSOR,
    NOTSENSOR,
};

//Representa para que lado de la pantalla esta "mirando"
//el auto.
enum FacingStatus {
    FACINGFRONT,
    FACINGBACK,
};

//Estado del auto segun si hizo algun salto
//o si esta en el suelo.
enum AirStatus {
    AIR,
    GROUND,
    AIRAFTERFLIP,
};

//Equipo del jugador.
enum PlayerSide {
    LEFTPLAYER,
    RIGHTPLAYER,
};

//Tipo de aceleracion del auto.
enum AcceleratingStatus {
    ACCELERATINGLEFT,
    ACCELERATINGRIGHT,
    NOTACCELERATING,
};

//Tipo de tiro especial que haya hecho el jugador.
enum MakeShot {
    DONTMAKESHOT,
    MAKEGOLDSHOT,
    MAKEPURPLESHOT,
    MAKEREDSHOT,
};

//Clase que representa al auto de cada jugador en el mundo de Box2D.
//Esta se encarga de implementar todos los comandos que el cliente
//quiera realizar en el juego, sean saltos, flips, tiros especiales,
//turbo, movimientos.
class CarPhysics {
private:
    b2Body* carBody;
    FacingStatus facingStatus;
    PlayerSide side;
    AirStatus airStatus;
    AcceleratingStatus acceleratingStatus;
    SensorStatus sensorStatus;
    bool isFliping;
    float flipStartAngle;
    bool isDoingTurbo;
    int turboRemaining;
    int clientId; 
    std::string playerName;

    int goals;
    int goalAssists;

    bool skipReplay;



    float FIELDHALFWIDTH = ServerConfig::getFieldHalfWidth();
    float FIELDHEIGHT = ServerConfig::getFieldHeight();
    float CARFRICTION = ServerConfig::getCarFriction();
    float CARHALFWIDTH = ServerConfig::getCarHalfWidth();
    float CARHALFHEIGHT = ServerConfig::getCarHalfHeight();
    float FRONTSENSORHALFWIDTH = ServerConfig::getFrontSensorHalfWidth();
    float BOTTOMSENSORHALFHEIGTH = ServerConfig::getBottomSensorHalfHeigth();
    float MOVEMENTFORCE = ServerConfig::getMovementForce();
    float TURBOFORCE = ServerConfig::getTurboForce();
    float JUMPIMPULSE = ServerConfig::getJumpImpulse();
    float ROTATIONANGULARVELOCITY = ServerConfig::getRotationAngularVelocity();
    float FLIPIMPULSE = ServerConfig::getFlipImpulse();
    float FLIPANGULARVEL = ServerConfig::getFlipAngularVel();
    float PI = ServerConfig::getPi();

    float MAXTURBO = ServerConfig::getMaxTurbo();


public:
    CarPhysics(int ClientId, std::string name, b2World& world, int numberOfCar);
    CarPhysics();
    b2Body* getCarBody();

    b2Body* createBody(b2World& world, int numberOfCar);

    void landed();
    void jumpedFromTheFloor();
    AirStatus getAirStatus();
    void setAirStatus(AirStatus status);
    FacingStatus getFacingStatus();

    void setSensorStatus(SensorStatus status);

    SensorStatus getSensorStatus();

    PlayerSide getSide();
    void setFacingStatus(FacingStatus status);
    void setDoingTurbo(bool doing);
    bool getDoingTurbo();

    void setAcceleratingStatus(AcceleratingStatus status);
    AcceleratingStatus getAcceleratingStatus();

    void flipJump();

    void jumpFromGround();

    void swapFrontBackSensor();
    void swapFacingStatus();
    void swapAcceleratingStatus();

    void updateFlipStatus();

    void loseTurbo();

    void fillTurbo();

    bool canUseTurbo();

    int getTurbo();

    void startAcceleratingForward();
    void startAcceleratingBackwards();
    
    void stopAccelerating();

    void applyAcceleration();

    void turn();

    bool jump(MakeShot& makeShot);

    void rotate(int sideMultiplicator);
    void stopRotate();

    void startDoingTurbo();
    void stopDoingTurbo();
    void applyTurbo();

    PlayerModel getPlayerModel();

    void scoreAGoal();
    void assistAGoal();

    int getGoalsScored();
    int getPlayerAssists();

    int getId();
    std::string getName();

    void setSkipReplay(bool skip);
    bool getSkipReplay();


};

#endif