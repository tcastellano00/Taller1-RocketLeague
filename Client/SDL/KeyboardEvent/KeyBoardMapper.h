#include <map>
#include <string>
#include <SDL2/SDL.h>

#include "../../../Common/Constants/ActionsClient.h"

#define CONFIG_ARROW_RIGHT "FlechitaDerecha"
#define CONFIG_ARROW_LEFT "FlechitaIzquierda"
#define CONFIG_ARROW_UP "FlechitaArriba"
#define CONFIG_ARROW_DOWN "FlechitaAbajo"
#define CONFIG_KEY_T "T"
#define CONFIG_KEY_W "W"
#define CONFIG_KEY_S "S"
#define CONFIG_KEY_D "D"
#define CONFIG_KEY_M "M"
#define CONFIG_KEY_A "A"
#define CONFIG_KEY_1 "1"
#define CONFIG_KEY_2 "2"
#define CONFIG_KEY_3 "3"
#define CONFIG_KEY_4 "4"
#define CONFIG_KEY_SPACE_BAR "SpaceBar"

class KeyBoardMapper {
private:
    std::map<const std::string, SDL_Keycode> MapSDLKeyCode;
    std::map<SDL_Keycode, std::string> MapActionsClientBySDLKeyCodeOnKeyDown;
    std::map<SDL_Keycode, std::string> MapActionsClientBySDLKeyCodeOnKeyUp;

    void initMapSDLKeyCode();
    void addKeyCodeAction(
        const std::string userConfig, 
        const std::string cientActionOnKeyDown);
    void addKeyCodeAction(
        const std::string userConfig, 
        const std::string cientActionOnKeyDown,
        const std::string cientActionOnKeyUp);

public:
    KeyBoardMapper();

    std::string getActionByKeyCodeOnKeyDown(SDL_Keycode keyCode);
    std::string getActionByKeyCodeOnKeyUp(SDL_Keycode keyCode);

    ~KeyBoardMapper() = default;
};