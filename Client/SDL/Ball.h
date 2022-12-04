#ifndef BALL_H
#define BALL_H
#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include "../../Common/Model/PlayerModel.h"
#include "../../Common/Model/BallModel.h"
#include <string>


class Ball{
    Animation anBall;
    Animation anExplosion;
    bool moving;
    float x;
    float y;
    float angle;
    std::string colour;
    bool finishedExplosion;


    public:
    Ball(SDL2pp::Texture &textureBall, SDL2pp::Texture &textureExplosion);
    void update(BallModel ballModel, int dt,bool isInExplosion);
    void render(SDL2pp::Renderer &renderer, bool isInExplosion);

    ~Ball();
};

#endif