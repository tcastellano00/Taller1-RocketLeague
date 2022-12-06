#ifndef CLIENT_CONFIG_H
#define CLIENT_CONFIG_H

#include <string>
#include <yaml-cpp/yaml.h>

/*
Esta clase se utiliza para almacenar mediante el patron singleton la
configuración del cliente. Todos sus atributos parametrizables, deben
encontrarse aqui.
*/
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
    static std::string getKeyCommandFlipShot();
    static std::string getKeyCommandRedShot();
    static std::string getKeyCommandPurpleShot();
    static std::string getKeyCommandGoldenShot();
    static std::string getKeyCommandPauseMusic();
    static std::string getKeyCommandNextMusic();
    static std::string getKeyCommandSkipReplay();
    static void deleteConfig();

    ClientConfig(ClientConfig &other) = delete;
    void operator=(ClientConfig const&) = delete;
    ~ClientConfig() = default;
};

#endif