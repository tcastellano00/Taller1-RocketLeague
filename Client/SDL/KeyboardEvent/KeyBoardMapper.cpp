#include "KeyBoardMapper.h"
#include "../../Config/ClientConfig.h"
#include "../../../Common/Constants/ActionsClient.h"

KeyBoardMapper::KeyBoardMapper() {
    this->initMapSDLKeyCode();

    this->addKeyCodeAction(ClientConfig::getKeyCommandMoveRight(), START_MOVING_RIGHT, STOP_MOVING_RIGHT);
    this->addKeyCodeAction(ClientConfig::getKeyCommandMoveLeft(), START_MOVING_LEFT, STOP_MOVING_LEFT);
    this->addKeyCodeAction(ClientConfig::getKeyCommandMoveUp(), START_FLIPING_RIGHT, STOP_FLIPING_RIGHT);
    this->addKeyCodeAction(ClientConfig::getKeyCommandMoveDown(), START_FLIPING_LEFT, STOP_FLIPING_LEFT);
    this->addKeyCodeAction(ClientConfig::getKeyCommandTurbo(), START_DOING_TURBO, STOP_DOING_TURBO);
    this->addKeyCodeAction(ClientConfig::getKeyCommandJump(), START_JUMPING, STOP_JUMPING);
    this->addKeyCodeAction(ClientConfig::getKeyCommandFlip(), START_FLIPING, STOP_FLIPING);
    this->addKeyCodeAction(ClientConfig::getKeyCommandSkipReplay(), SKIP_REPLAY, "");
}

void KeyBoardMapper::initMapSDLKeyCode() {
    this->MapSDLKeyCode[CONFIG_ARROW_RIGHT] = SDLK_RIGHT;
    this->MapSDLKeyCode[CONFIG_ARROW_LEFT] = SDLK_LEFT;
    this->MapSDLKeyCode[CONFIG_ARROW_UP] = SDLK_UP;
    this->MapSDLKeyCode[CONFIG_ARROW_DOWN] = SDLK_DOWN;
    this->MapSDLKeyCode[CONFIG_KEY_T] = SDLK_t;
    this->MapSDLKeyCode[CONFIG_KEY_W] = SDLK_w;
    this->MapSDLKeyCode[CONFIG_KEY_S] = SDLK_s;
    this->MapSDLKeyCode[CONFIG_KEY_D] = SDLK_d;
    this->MapSDLKeyCode[CONFIG_KEY_M] = SDLK_m;
    this->MapSDLKeyCode[CONFIG_KEY_A] = SDLK_a;
    this->MapSDLKeyCode[CONFIG_KEY_1] = SDLK_1;
    this->MapSDLKeyCode[CONFIG_KEY_2] = SDLK_2;
    this->MapSDLKeyCode[CONFIG_KEY_3] = SDLK_3;
    this->MapSDLKeyCode[CONFIG_KEY_4] = SDLK_4;
    this->MapSDLKeyCode[CONFIG_KEY_SPACE_BAR] = SDLK_SPACE;
}

void KeyBoardMapper::addKeyCodeAction(
    const std::string userConfig, 
    const std::string cientActionOnKeyDown,
    const std::string cientActionOnKeyUp) {

    SDL_Keycode keyCode = this->MapSDLKeyCode[userConfig];
    this->MapActionsClientBySDLKeyCodeOnKeyDown[keyCode] = cientActionOnKeyDown;
    this->MapActionsClientBySDLKeyCodeOnKeyUp[keyCode] = cientActionOnKeyUp;
}

std::string KeyBoardMapper::getActionByKeyCodeOnKeyDown(SDL_Keycode keyCode) {
    if (this->MapActionsClientBySDLKeyCodeOnKeyDown.find(keyCode) == 
        this->MapActionsClientBySDLKeyCodeOnKeyDown.end())
        return "";

    return this->MapActionsClientBySDLKeyCodeOnKeyDown[keyCode];
}

std::string KeyBoardMapper::getActionByKeyCodeOnKeyUp(SDL_Keycode keyCode) {
    if (this->MapActionsClientBySDLKeyCodeOnKeyUp.find(keyCode) == 
        this->MapActionsClientBySDLKeyCodeOnKeyUp.end())
        return "";

    return this->MapActionsClientBySDLKeyCodeOnKeyUp[keyCode];
}