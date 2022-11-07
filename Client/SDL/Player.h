#ifndef __WORM_H__
#define __WORM_H__

#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include "../Model/PlayerModel.h"

class Player {
public:
    Player(SDL2pp::Texture &texture);
    ~Player();
    void update(int newXPos, int dt); //PlayerModel playerModel);
    void render(SDL2pp::Renderer &renderer);
    

private:
    Animation an;
    bool facingLeft;
    bool moving;
    int x;
    int y;
};

#endif // __WORM_H__