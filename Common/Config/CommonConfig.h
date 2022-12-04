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

    CommonConfig(CommonConfig &other) = delete;
    void operator=(CommonConfig const&) = delete;
    ~CommonConfig() = default;
};