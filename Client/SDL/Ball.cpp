#include "Ball.h"


Ball::Ball(SDL2pp::Texture &texture): an(texture),moving(false), x(370), y(400) {}


void Ball::render(SDL2pp::Renderer &renderer){
    //SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    an.render(renderer, SDL2pp::Rect(x, y, 50, 60),flip);
}

Ball::~Ball(){}