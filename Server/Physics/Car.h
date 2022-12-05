#ifndef CARPHYSICS_H
#define CARPHYSICS_H

#include "../Box2D/Box2D.h"
#include "BallPhysics.h"
#include "../../Common/Model/PlayerModel.h"
#include "../../Common/Config/ServerConfig.h"
// class CarPhisics{
//     b2World * &m_world;
    
//     public:
//     CarPhisics(b2World * &m_world);
// };

enum SensorStatus {   
    BALLINFRONTSENSOR,
    BALLINBOTTOMSENSOR,
    BALLINBACKSENSOR,
    NOTSENSOR,
};

enum FacingStatus {
    FACINGFRONT,
    FACINGBACK,
};

enum AirStatus {
    AIR,
    GROUND,
    AIRAFTERFLIP,
};

enum PlayerSide {
    LEFTPLAYER,
    RIGHTPLAYER,
};

enum AcceleratingStatus {
    ACCELERATINGLEFT,
    ACCELERATINGRIGHT,
    NOTACCELERATING,
};


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
    CarPhysics(int ClientId,b2World& world, int numberOfCar);
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

    void jump(BallPhysics* ball);

    void rotate(int sideMultiplicator);
    void stopRotate();

    void startDoingTurbo();
    void stopDoingTurbo();
    void applyTurbo();

    PlayerModel getPlayerModel();


};

#endif