#include "ReplayFrame.h"
#include <iostream>

ReplayFrame::ReplayFrame(SDL2pp::Texture &texture): an(texture, 1, 1) {}


void ReplayFrame::render(SDL2pp::Renderer &renderer){
    //SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    an.render(renderer, SDL2pp::Rect(0, 0, SCREENWIDTH, SCREENHEIGHT),flip, 0);
    
}

ReplayFrame::~ReplayFrame(){}