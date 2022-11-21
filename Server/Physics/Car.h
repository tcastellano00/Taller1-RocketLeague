#ifndef CARPHYSICS_H
#define CARPHYSICS_H

#include "../Box2D/Box2D.h"

// class CarPhisics{
//     b2World * &m_world;
    
//     public:
//     CarPhisics(b2World * &m_world);
// };

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


class CarPhysics {
private:
    b2Body* carBody;
    FacingStatus facingStatus;
    PlayerSide side;
    AirStatus airStatus;
    bool ballInFrontSensor;
    bool ballInBackSensor;
    bool ballInBottomSensor;
    bool isDoingTurbo;

public:
    CarPhysics(b2Body* body, PlayerSide side);
    CarPhysics();
    b2Body* getCarBody();

    void landed();
    void jumpedFromTheFloor();
    AirStatus getAirStatus();
    void setAirStatus(AirStatus status);
    FacingStatus getFacingStatus();

    void setBallInFrontSensor(bool cond);
    void setBallInBackSensor(bool cond);
    void setBallInBottomSensor(bool cond);

    bool getBallInFrontSensor();
    bool getBallInBackSensor();
    bool getBallInBottomSensor();

    PlayerSide getSide();
    void setFacingStatus(FacingStatus status);
    void setDoingTurbo(bool doing);
    bool getDoingTurbo();
};

#endif