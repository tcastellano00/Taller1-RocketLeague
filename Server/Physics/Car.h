#ifndef CARPHYSICS_H
#define CARPHYSICS_H

#include "../Box2D/Box2D.h"

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


public:
    CarPhysics(b2World& world, int numberOfCar);
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

    void swapFrontBackSensor();

    void updateFlipStatus();

    void loseTurbo();

    void fillTurbo();

    bool canUseTurbo();

    int getTurbo();

};

#endif