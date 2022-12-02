#include <string>
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

    static std::string getKeyCommandMoveRight();
    static std::string getKeyCommandMoveLeft();
    static std::string getKeyCommandMoveUp();
    static std::string getKeyCommandMoveDown();
    static std::string getKeyCommandTurbo();
    static std::string getKeyCommandJump();
    static std::string getKeyCommandFlip();
    static std::string getKeyCommandSkipReplay();

    ClientConfig(ClientConfig &other) = delete;
    void operator=(ClientConfig const&) = delete;
    ~ClientConfig() = default;
};