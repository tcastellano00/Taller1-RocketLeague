#include "Ball.h"
#include "CoordsTransformator.h"
#include <iostream>

Ball::Ball(SDL2pp::Texture &textureBall,SDL2pp::Texture &textureExplosion)
: anBall(textureBall, 1, 1),anExplosion(textureExplosion,6,8),moving(false), x(370), y(400), angle(0), finishedExplosion(false), explosionX(0), explosionY(0) {}


void Ball::render(SDL2pp::Renderer &renderer, bool isInExplosion){
    //SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    
    if (isInExplosion) {
        if (!finishedExplosion) {
            contador++;
            anExplosion.render(renderer, SDL2pp::Rect(explosionX-BALLRADIUS, explosionY-BALLRADIUS, BALLRADIUS*3, BALLRADIUS*3),flip, 0);
        }
        
    } else {
        this->finishedExplosion = false;

        if (colour == "normal") {
            anBall.getTexture().SetColorMod(255, 255, 255);
        } else if (colour == "gold") {
            anBall.getTexture().SetColorMod(212, 175, 55);  
        } else if (colour == "purple") {
            anBall.getTexture().SetColorMod(159, 0, 255);
        } else if (colour == "red") {
            anBall.getTexture().SetColorMod(255, 0, 0); 
        }
        anBall.render(renderer, SDL2pp::Rect(x, y, BALLRADIUS*2, BALLRADIUS*2),flip, angle);
    }

    std::cout  << contador << std::endl;

   
    
}

void Ball::update(BallModel ballModel, int dt,bool isInExplosion) {
    float newXPos = ballModel.getCoordX();
    float newYpos = ballModel.getCoordY();

    float newXPosTransformed = CoordsTransformator::transformX(newXPos);
    float newYPosTransformed = CoordsTransformator::transformY(newYpos);
    
    anBall.update(dt);
    this->x = newXPosTransformed;
    this->y = newYPosTransformed;
    this->angle = CoordsTransformator::radianToDegree(ballModel.getAngle());
    this->colour = ballModel.getColour();

    if (isInExplosion && !finishedExplosion) {
        bool endedExplosion = anExplosion.update(dt);
        if (endedExplosion) {
            this->finishedExplosion = true;
            std::cout << "termino: SI" << std::endl;
        } else {
            std::cout << "termino: NO" << std::endl;
        }
    } else {
        this->explosionX = this->x;
        this->explosionY = this->y;
    }
    
    


}
Ball::~Ball(){}