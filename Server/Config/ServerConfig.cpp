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

int ServerConfig::getGravity() {
    return getInstance()->rootNode["GRAVITY"].as<int>();
}