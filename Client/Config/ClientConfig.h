#include <yaml-cpp/yaml.h>

class ClientConfig {
private:
    static ClientConfig* clientConfig;
    
    YAML::Node rootNode;

    static ClientConfig *getInstance();
    
public:
    ClientConfig();

    static int getScreenWidth();
    static int getScreenHeight();

    ClientConfig(ClientConfig &other) = delete;
    void operator=(ClientConfig const&) = delete;
    ~ClientConfig() = default;
};