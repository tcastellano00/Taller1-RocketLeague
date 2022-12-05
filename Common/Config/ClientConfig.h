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

    static std::string getKeyCommandMoveForward();
    static std::string getKeyCommandMoveBackwards();
    static std::string getKeyCommandMoveUp();
    static std::string getKeyCommandMoveDown();
    static std::string getKeyCommandTurbo();
    static std::string getKeyCommandJump();
    static std::string getKeyCommandTurn();
    static std::string getKeyCommandSkipReplay();
    static std::string getKeyCommandFlipShot();
    static std::string getKeyCommandRedShot();
    static std::string getKeyCommandPurpleShot();
    static std::string getKeyCommandGoldenShot();
    static std::string getKeyCommandPauseMusic();
    static std::string getKeyCommandNextMusic();

    ClientConfig(ClientConfig &other) = delete;
    void operator=(ClientConfig const&) = delete;
    ~ClientConfig() = default;
};