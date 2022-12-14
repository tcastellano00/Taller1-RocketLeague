#ifndef SERVERCONFIG_H
#define SERVERCONFIG_H

#include <yaml-cpp/yaml.h>

/*
Esta clase se utiliza para almacenar mediante el patron singleton la
configuración del servidor. Todos sus atributos parametrizables, deben
encontrarse aqui.
*/
class ServerConfig {
private:
    static ServerConfig* serverConfig;
    
    YAML::Node rootNode;

    static ServerConfig *getInstance();
    
public:
    ServerConfig();

    static float getGravity();

    ServerConfig(ServerConfig &other) = delete;
    void operator=(ServerConfig const&) = delete;
    
    static float getMaxTurbo();
    
    static float getGameTime();
    static float getExtraTime();
    static float getReplayTime();
    static float getFlipImpulse();
    static float getFlipAngularVel();
    static float getCarHalfWidth();
    static float getCarHalfHeight();
    static float getTurboForce();
    static float getJumpImpulse();
    static float getMovementForce();
    static float getCarFriction();
    static float getFrontSensorHalfWidth();
    static float getBottomSensorHalfHeigth();


    static float getWallWidth();
    static float getGroundFriction();
    
    static float getFieldHalfWidth();
    static float getFieldHeight();

    static float getGoalTopHalfWidth();
    static float getGoalTopHalfHeight();
    static float getBallRadius();

    static float getRedShotImpulse();
    static float getGoldShotImpulse();
    static float getPurpleShotImpulse();
    static float getSpecialShotTime();
    static float getRotationAngularVelocity();

    static float getPi();

    static void deleteConfig();
    
    ~ServerConfig() = default;
};

#endif