#ifndef CLIENT_SDL_PLAYER_H__
#define CLIENT_SDL_PLAYER_H__

#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include "CoordsTransformator.h"
#include "../../Common/Model/PlayerModel.h"
#include "../../Common/Config/ServerConfig.h"
#include "../../Common/Config/ClientConfig.h"




class Player {
public:
    Player(SDL2pp::Texture &textureCar, SDL2pp::Texture &textureTurbo, SDL2pp::Texture &textureTurboBarEmpty, SDL2pp::Texture &textureTurboBarFull);
    ~Player();
    void update(PlayerModel playerModel, int dt);
    void render(SDL2pp::Renderer &renderer, int i);

private:
    Animation anCar;
    Animation anTurbo;
    Animation anTurboBarEmpty;
    Animation anTurboBarFull;
    bool facingLeft;
    bool moving;
    float x;
    float y;
    float angle;
    bool turbo;
    int turboRemaining;

    float SCREENWIDTH = ClientConfig::getScreenWidth();
    float SCREENHEIGHT = SCREENWIDTH/3;
    float CAR_WIDTH = CoordsTransformator::transformX(ServerConfig::getCarHalfWidth()*2);
    float CAR_HEIGHT = CoordsTransformator::transformX(ServerConfig::getCarHalfHeight()*2); 
    float MAXTURBO = ServerConfig::getMaxTurbo();
    float TURBOBARX = SCREENWIDTH/9;
    float TURBOBARY = SCREENHEIGHT/20;
    float TURBOBARHEIGHT = SCREENHEIGHT/20;
    float TURBOBARWIDTH  =SCREENWIDTH/18;

};

#endif // __WORM_H__