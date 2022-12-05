#ifndef REPLAYFRAME_H
#define REPLAYFRAME_H
#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include <string>
#include "../../Common/Config/ClientConfig.h"



class ReplayFrame{
    Animation an;

    float SCREENWIDTH = ClientConfig::getScreenWidth();
    float SCREENHEIGHT = SCREENWIDTH/3;

    public:
    ReplayFrame(SDL2pp::Texture &texture);
    void render(SDL2pp::Renderer &renderer);

    ~ReplayFrame();
};

#endif