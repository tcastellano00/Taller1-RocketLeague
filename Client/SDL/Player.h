#ifndef CLIENT_SDL_PLAYER_H__
#define CLIENT_SDL_PLAYER_H__

#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include "../../Common/Model/PlayerModel.h"

class Player {
public:
    Player(SDL2pp::Texture &texture);
    ~Player();
    void update(PlayerModel playerModel, int dt);
    void render(SDL2pp::Renderer &renderer);

private:
    Animation an;
    bool facingLeft;
    bool moving;
    int x;
    int y;
};

#endif // __WORM_H__