#include "CommonConfig.h"
#include <iostream>

CommonConfig* CommonConfig::commonConfig = nullptr;

CommonConfig::CommonConfig() {
    std::string configFile = "config/common.yaml";

    this->rootNode = YAML::LoadFile(configFile);
}

CommonConfig* CommonConfig::getInstance() {
    if (commonConfig == nullptr) {
        commonConfig = new CommonConfig();
    }

    return commonConfig;
}

float CommonConfig::getFrameRate() {
    return getInstance()->rootNode["FRAME_RATE"].as<float>();
}

float CommonConfig::getFrameTimeInMicroseconds() {
    return 1000000.0f / CommonConfig::getFrameRate();
}

void CommonConfig::deleteConfig() {
    if (commonConfig != nullptr)
        delete commonConfig;
}