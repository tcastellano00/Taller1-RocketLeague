#include "ServerConfig.h"

ServerConfig* ServerConfig::serverConfig = nullptr;;

ServerConfig::ServerConfig() {
    std::string configFile = "config/server.yaml";

    this->rootNode = YAML::LoadFile(configFile);
}

ServerConfig* ServerConfig::getInstance() {
    if (serverConfig == nullptr) {
        serverConfig = new ServerConfig();
    }

    return serverConfig;
}

float ServerConfig::getGravity() {
    return getInstance()->rootNode["GRAVITY"].as<float>();
}

float ServerConfig::getGameTime() {
    return getInstance()->rootNode["GAME_TIME"].as<float>();
}

float ServerConfig::getExtraTime() {
    return getInstance()->rootNode["EXTRA_TIME"].as<float>();
}

float ServerConfig::getReplayTime() {
    return getInstance()->rootNode["REPLAY_TIME"].as<float>();
}

float ServerConfig::getFlipImpulse() {
    return getInstance()->rootNode["FLIP_IMPULSE"].as<float>();
}

float ServerConfig::getFlipAngularVel() {
    return getInstance()->rootNode["FLIP_ANGULAR_VEL"].as<float>();
}

float ServerConfig::getCarHalfWidth() {
    return getInstance()->rootNode["CAR_HALF_WIDTH"].as<float>();
}

float ServerConfig::getCarHalfHeight() {
    return getInstance()->rootNode["CAR_HALF_HEIGHT"].as<float>();
}

float ServerConfig::getTurboForce() {
    return getInstance()->rootNode["TURBO_FORCE"].as<float>();
}

float ServerConfig::getJumpImpulse() {
    return getInstance()->rootNode["JUMP_IMPULSE"].as<float>();
}

float ServerConfig::getMovementForce() {
    return getInstance()->rootNode["MOVEMENT_FORCE"].as<float>();
}

float ServerConfig::getCarFriction() {
    return getInstance()->rootNode["CAR_FRICTION"].as<float>();
}

float ServerConfig::getFrontSensorHalfWidth() {
    return getInstance()->rootNode["FRONT_SENSOR_HALF_WIDTH"].as<float>();
}

float ServerConfig::getBottomSensorHalfHeigth() {
    return getInstance()->rootNode["BOTTOM_SENSOR_HALF_HEIGHT"].as<float>();
}



float ServerConfig::getWallWidth() {
    return getInstance()->rootNode["WALL_WIDTH"].as<float>();
}

float ServerConfig::getGroundFriction() {
    return getInstance()->rootNode["GROUND_FRICTION"].as<float>();
}


float ServerConfig::getFieldHalfWidth() {
    return getInstance()->rootNode["FIELD_HALF_WIDTH"].as<float>();
}

float ServerConfig::getFieldHeight() {
    return getInstance()->rootNode["FIELD_HEIGHT"].as<float>();
}


float ServerConfig::getGoalTopHalfWidth() {
    return getInstance()->rootNode["GOAL_TOP_HALF_WIDTH"].as<float>();
}

float ServerConfig::getGoalTopHalfHeight() {
    return getInstance()->rootNode["GOAL_TOP_HALF_HEIGHT"].as<float>();
}

float ServerConfig::getBallRadius() {
    return getInstance()->rootNode["BALL_RADIUS"].as<float>();
}


float ServerConfig::getRedShotImpulse() {
    return getInstance()->rootNode["RED_SHOT_IMPULSE"].as<float>();
}

float ServerConfig::getGoldShotImpulse() {
    return getInstance()->rootNode["GOLD_SHOT_IMPULSE"].as<float>();
}

float ServerConfig::getPurpleShotImpulse() {
    return getInstance()->rootNode["PURPLE_SHOT_IMPULSE"].as<float>();
}

float ServerConfig::getSpecialShotTime() {
    return getInstance()->rootNode["SPECIAL_SHOT_TIME"].as<float>();
}

float ServerConfig::getRotationAngularVelocity(){
    return getInstance()->rootNode["ROTATION_ANGULAR_VELOCITY"].as<float>();
}