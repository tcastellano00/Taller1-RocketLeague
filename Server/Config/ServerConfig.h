#include <yaml-cpp/yaml.h>

class ServerConfig {
private:
    static ServerConfig* serverConfig;
    
    YAML::Node rootNode;

    static ServerConfig *getInstance();
    
public:
    ServerConfig();

    static int getGravity();

    ServerConfig(ServerConfig &other) = delete;
    void operator=(ServerConfig const&) = delete;
    ~ServerConfig() = default;
};