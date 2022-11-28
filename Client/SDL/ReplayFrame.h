#ifndef REPLAYFRAME_H
#define REPLAYFRAME_H
#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include <string>
#define SCREENWIDTH 1800
#define SCREENHEIGHT 600


class ReplayFrame{
    Animation an;

    public:
    ReplayFrame(SDL2pp::Texture &texture);
    void render(SDL2pp::Renderer &renderer);

    ~ReplayFrame();
};

#endif