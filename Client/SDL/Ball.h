#ifndef BALL_H
#define BALL_H
#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include "../Model/PlayerModel.h"

class Ball{
    Animation an;
    bool moving;
    int x;
    int y;

    public:
    Ball(SDL2pp::Texture &texture);
    //void update(int newXPos, int dt);
    void render(SDL2pp::Renderer &renderer);

    ~Ball();
};

#endif