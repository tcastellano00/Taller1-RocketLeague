#include "Ball.h"
#include "CoordsTransformator.h"
#include <iostream>

Ball::Ball(SDL2pp::Texture &texture): an(texture, 1, 1),moving(false), x(370), y(400), angle(0) {}


void Ball::render(SDL2pp::Renderer &renderer){
    //SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    if (colour == "normal") {
        an.getTexture().SetColorMod(255, 255, 255);
    } else if (colour == "gold") {
        an.getTexture().SetColorMod(212, 175, 55);  
    } else if (colour == "purple") {
        an.getTexture().SetColorMod(159, 0, 255);
    } else if (colour == "red") {
        an.getTexture().SetColorMod(255, 0, 0); 
    }
    an.render(renderer, SDL2pp::Rect(x, y, 100, 100),flip, angle);
    
}

void Ball::update(BallModel ballModel, int dt) {
    float newXPos = ballModel.getCoordX();
    float newYpos = ballModel.getCoordY();

    float newXPosTransformed = CoordsTransformator::transformX(newXPos);
    float newYPosTransformed = CoordsTransformator::transformY(newYpos);
    
    an.update(dt);
    this->x = newXPosTransformed;
    this->y = newYPosTransformed;
    this->angle = CoordsTransformator::radianToDegree(ballModel.getAngle());
    this->colour = ballModel.getColour();
    


}
Ball::~Ball(){}