#include "Player.h"
#include "CoordsTransformator.h"
#include <iostream>

Player::Player(SDL2pp::Texture &textureCar, SDL2pp::Texture &textureTurbo, SDL2pp::Texture &textureTurboBarEmpty, SDL2pp::Texture &textureTurboBarFull) : 
    anCar(textureCar, 1, 1), 
    anTurbo(textureTurbo, 1, 1),
    anTurboBarEmpty(textureTurboBarEmpty, 1, 1),
    anTurboBarFull(textureTurboBarFull, 1, 1),
    facingLeft(false), 
    moving(false),
    turbo(false),
    turboRemaining(MAXTURBO) {}

Player::~Player() {}

void Player::update(PlayerModel playerModel, int dt) {
    float newXPos = playerModel.getCoordX();
    float newYpos = playerModel.getCoordY();

    float newXPosTransformed = CoordsTransformator::transformX(newXPos);
    float newYPosTransformed = CoordsTransformator::transformY(newYpos);

    //std::string facing = playerModel.getFacing();
    
    /*
    if(facing == "left"){
        facingLeft = true;
    }
    else{
        facingLeft = false;
    }*/

    anCar.update(dt);
    anTurbo.update(dt);
    anTurboBarEmpty.update(dt);
    anTurboBarFull.update(dt);
    this->x = newXPosTransformed;
    this->y = newYPosTransformed;
    this->angle = CoordsTransformator::radianToDegree(playerModel.getAngle());
    this->turbo = playerModel.isDoingTurbo();
    this->facingLeft = (playerModel.getFacing() == "left");
    this->turboRemaining = playerModel.getTurboRemaining();

}

void Player::render(SDL2pp::Renderer &renderer, int i) {
    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    
    if (not turbo) 
        anCar.render(renderer, SDL2pp::Rect(x, y, CAR_WIDTH, CAR_HEIGHT), flip, angle);
    else
        anTurbo.render(renderer, SDL2pp::Rect(x - 50, y, CAR_WIDTH + 50, CAR_HEIGHT), flip, angle);
    
    flip = SDL_FLIP_NONE;
        
    if (i == 0) {
        float barPercentage = turboRemaining/MAXTURBO;
        anTurboBarFull.render(renderer, SDL2pp::Rect(TURBOBARX, TURBOBARY, TURBOBARWIDTH * barPercentage, TURBOBARHEIGHT), flip, 0);
        anTurboBarEmpty.render(renderer, SDL2pp::Rect(TURBOBARX, TURBOBARY, TURBOBARWIDTH, TURBOBARHEIGHT), flip, 0);
    } else if (i == 1) {
        float barPercentage = turboRemaining/MAXTURBO;
        anTurboBarFull.render(renderer, SDL2pp::Rect(SCREENWIDTH - TURBOBARX - TURBOBARWIDTH * barPercentage, TURBOBARY, TURBOBARWIDTH * barPercentage, TURBOBARHEIGHT), flip, 0);
        anTurboBarEmpty.render(renderer, SDL2pp::Rect(SCREENWIDTH - TURBOBARX - TURBOBARWIDTH, TURBOBARY, TURBOBARWIDTH, TURBOBARHEIGHT), flip, 0);
    }

    /*
    if (turbo) {
        anTurbo.render(renderer, SDL2pp::Rect(x -CAR_HEIGHT, y,
         CAR_HEIGHT, CAR_HEIGHT), flip, angle);
    }
    */

}

