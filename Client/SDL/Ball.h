#ifndef BALL_H
#define BALL_H
#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include "../../Common/Model/PlayerModel.h"
#include "../../Common/Model/BallModel.h"


class Ball{
    Animation an;
    bool moving;
    float x;
    float y;
    float angle;
    int cont;

    public:
    Ball(SDL2pp::Texture &texture);
    void update(BallModel ballModel, int dt);
    void render(SDL2pp::Renderer &renderer);

    ~Ball();
};

#endif