#ifndef CLIENT_SDL_PLAYER_H__
#define CLIENT_SDL_PLAYER_H__

#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include "../../Common/Model/PlayerModel.h"

#define CAR_WIDTH 150
#define CAR_HEIGHT 40

class Player {
public:
    Player(SDL2pp::Texture &textureCar, SDL2pp::Texture &textureTurbo);
    ~Player();
    void update(PlayerModel playerModel, int dt);
    void render(SDL2pp::Renderer &renderer);

private:
    Animation anCar;
    Animation anTurbo;
    bool facingLeft;
    bool moving;
    float x;
    float y;
    float angle;
    bool turbo;

};

#endif // __WORM_H__