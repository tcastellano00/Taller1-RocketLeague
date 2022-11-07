#include "Bow.h"


Bow::Bow(SDL2pp::Texture &texture, int coordX,bool left): an(texture), x(coordX), y(300),facingLeft(left) {}


void Bow::render(SDL2pp::Renderer &renderer){
    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    an.render(renderer, SDL2pp::Rect(x, y, 100, 150),flip);
}

Bow::~Bow(){}