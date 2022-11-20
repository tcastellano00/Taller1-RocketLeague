#ifndef TIMER_H
#define TIMER_H

#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include <list>
#include "../../Common/Model/ScoreModel.h"
#include <vector>

class Timer{

    public:

    Timer();

    void update(ScoreModel scoreModel, int dt);
    void render(SDL2pp::Renderer &renderer);

    ~Timer();
};

#endif