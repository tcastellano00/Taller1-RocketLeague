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