#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H

#include <string>
#include <yaml-cpp/yaml.h>

class CommonConfig {
private:
    static CommonConfig* commonConfig;
    
    YAML::Node rootNode;

    static CommonConfig *getInstance();
    
public:
    CommonConfig();

    static float getFrameRate();
    static float getFrameTimeInMicroseconds();

    static void deleteConfig();

    CommonConfig(CommonConfig &other) = delete;
    void operator=(CommonConfig const&) = delete;
    ~CommonConfig() = default;
};

#endif