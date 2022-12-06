#include <map>
#include <string>
#include <SDL2/SDL.h>

#include "../../../Common/Constants/ActionsClient.h"

/*
Este mapeo se hizo para que al usuario le resulte mas facil
configurar el client.yaml a la hora de elegir teclas quiere
usar para cada accion.
*/
#define CONFIG_ARROW_RIGHT "FlechitaDerecha"
#define CONFIG_ARROW_LEFT "FlechitaIzquierda"
#define CONFIG_ARROW_UP "FlechitaArriba"
#define CONFIG_ARROW_DOWN "FlechitaAbajo"
#define CONFIG_KEY_T "T"
#define CONFIG_KEY_W "W"
#define CONFIG_KEY_S "S"
#define CONFIG_KEY_D "D"
#define CONFIG_KEY_R "R"
#define CONFIG_KEY_M "M"
#define CONFIG_KEY_N "N"
#define CONFIG_KEY_A "A"
#define CONFIG_KEY_1 "1"
#define CONFIG_KEY_2 "2"
#define CONFIG_KEY_3 "3"
#define CONFIG_KEY_4 "4"
#define CONFIG_KEY_SPACE_BAR "SpaceBar"


/*
Esta clase es utilizada por el ThreadCmdReader para saber que accion enviar al
servidor cuando se presiona una determinada tecla.
*/
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

    /* Obtiene la accion configurada por el cliente para la tecla on key down */
    std::string getActionByKeyCodeOnKeyDown(SDL_Keycode keyCode);

    /* Obtiene la accion configurada por el cliente para la tecla on key up */
    std::string getActionByKeyCodeOnKeyUp(SDL_Keycode keyCode);

    ~KeyBoardMapper() = default;
};