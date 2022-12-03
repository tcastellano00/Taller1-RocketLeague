#include "ClientConfig.h"

ClientConfig* ClientConfig::clientConfig = nullptr;;

ClientConfig::ClientConfig() {
    std::string configFile = "config/client.yaml";

    this->rootNode = YAML::LoadFile(configFile);
}

ClientConfig* ClientConfig::getInstance() {
    if (clientConfig == nullptr) {
        clientConfig = new ClientConfig();
    }

    return clientConfig;
}

int ClientConfig::getScreenWidth() {
    return getInstance()->rootNode["SCREEN_WIDTH"].as<int>();
}

int ClientConfig::getScreenHeight() {
    return getInstance()->rootNode["SCREEN_HEIGHT"].as<int>();
}

std::string ClientConfig::getKeyCommandMoveForward() {
    return getInstance()->rootNode["KEY_COMMAND_MOVE_RIGHT"].as<std::string>();
}

std::string ClientConfig::getKeyCommandMoveBackwards() {
    return getInstance()->rootNode["KEY_COMMAND_MOVE_LEFT"].as<std::string>();
}

std::string ClientConfig::getKeyCommandMoveUp() {
    return getInstance()->rootNode["KEY_COMMAND_MOVE_UP"].as<std::string>();
}

std::string ClientConfig::getKeyCommandMoveDown() {
    return getInstance()->rootNode["KEY_COMMAND_MOVE_DOWN"].as<std::string>();
}

std::string ClientConfig::getKeyCommandTurbo() {
    return getInstance()->rootNode["KEY_COMMAND_TURBO"].as<std::string>();
}

std::string ClientConfig::getKeyCommandJump() {
    return getInstance()->rootNode["KEY_COMMAND_JUMP"].as<std::string>();
}

std::string ClientConfig::getKeyCommandTurn() {
    return getInstance()->rootNode["KEY_COMMAND_TURN"].as<std::string>();
}

std::string ClientConfig::getKeyCommandSkipReplay() {
    return getInstance()->rootNode["KEY_COMMAND_SKIP_REPLAY"].as<std::string>();
}

std::string ClientConfig::getKeyCommandFlipShot() {
    return getInstance()->rootNode["KEY_COMMAND_FLIP_SHOT"].as<std::string>();
}

std::string ClientConfig::getKeyCommandRedShot() {
    return getInstance()->rootNode["KEY_COMMAND_RED_SHOT"].as<std::string>();
}

std::string ClientConfig::getKeyCommandPurpleShot() {
    return getInstance()->rootNode["KEY_COMMAND_PRUPLE_SHOT"].as<std::string>();
}

std::string ClientConfig::getKeyCommandGoldenShot() {
    return getInstance()->rootNode["KEY_COMMAND_GOLDEN_SHOT"].as<std::string>();
}