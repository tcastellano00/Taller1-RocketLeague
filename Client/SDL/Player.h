#ifndef CLIENT_SDL_PLAYER_H__
#define CLIENT_SDL_PLAYER_H__

#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include "../../Common/Model/PlayerModel.h"

#define CAR_WIDTH 110
#define CAR_HEIGHT 30
#define MAXTURBO 50.0
#define TURBOBARX 200
#define TURBOBARY 27
#define TURBOBARHEIGHT 30
#define TURBOBARWIDTH  100
#define SCREENWIDTH 1800
#define SCREENHEIGHT 600

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

};

#endif // __WORM_H__