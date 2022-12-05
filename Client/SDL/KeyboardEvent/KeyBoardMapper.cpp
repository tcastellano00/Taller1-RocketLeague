#include "KeyBoardMapper.h"
#include "../../../Common/Config/ClientConfig.h"
#include "../../../Common/Constants/ActionsClient.h"

KeyBoardMapper::KeyBoardMapper() {
    this->initMapSDLKeyCode();

    this->addKeyCodeAction(ClientConfig::getKeyCommandMoveForward(), START_ACCELERATING_FORWARD, STOP_ACCELERATING);
    this->addKeyCodeAction(ClientConfig::getKeyCommandMoveBackwards(), START_ACCELERATING_BACKWARDS, STOP_ACCELERATING);
    this->addKeyCodeAction(ClientConfig::getKeyCommandMoveUp(), START_FLIPING_RIGHT, STOP_FLIPING);
    this->addKeyCodeAction(ClientConfig::getKeyCommandMoveDown(), START_FLIPING_LEFT, STOP_FLIPING);
    this->addKeyCodeAction(ClientConfig::getKeyCommandTurbo(), START_DOING_TURBO, STOP_DOING_TURBO);
    this->addKeyCodeAction(ClientConfig::getKeyCommandJump(), START_JUMPING, STOP_JUMPING);
    this->addKeyCodeAction(ClientConfig::getKeyCommandTurn(), START_TURNING, STOP_TURNING);
    this->addKeyCodeAction(ClientConfig::getKeyCommandFlipShot(), DO_FLIP_SHOT);
    this->addKeyCodeAction(ClientConfig::getKeyCommandRedShot(), DO_RED_SHOT);
    this->addKeyCodeAction(ClientConfig::getKeyCommandGoldenShot(), DO_GOLDEN_SHOT);
    this->addKeyCodeAction(ClientConfig::getKeyCommandPurpleShot(), DO_PURPLE_SHOT);
    this->addKeyCodeAction(ClientConfig::getKeyCommandSkipReplay(), SKIP_REPLAY);
    this->addKeyCodeAction(ClientConfig::getKeyCommandPauseMusic(), PAUSE_MUSIC);
    this->addKeyCodeAction(ClientConfig::getKeyCommandNextMusic(), NEXT_MUSIC);
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
    this->MapSDLKeyCode[CONFIG_KEY_N] = SDLK_n;
    this->MapSDLKeyCode[CONFIG_KEY_R] = SDLK_r;
    this->MapSDLKeyCode[CONFIG_KEY_A] = SDLK_a;
    this->MapSDLKeyCode[CONFIG_KEY_1] = SDLK_1;
    this->MapSDLKeyCode[CONFIG_KEY_2] = SDLK_2;
    this->MapSDLKeyCode[CONFIG_KEY_3] = SDLK_3;
    this->MapSDLKeyCode[CONFIG_KEY_4] = SDLK_4;
    this->MapSDLKeyCode[CONFIG_KEY_SPACE_BAR] = SDLK_SPACE;
}

void KeyBoardMapper::addKeyCodeAction(
        const std::string userConfig, 
        const std::string cientActionOnKeyDown) {

    SDL_Keycode keyCode = this->MapSDLKeyCode[userConfig];
    this->MapActionsClientBySDLKeyCodeOnKeyDown[keyCode] = cientActionOnKeyDown;
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