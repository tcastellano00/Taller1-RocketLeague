#include "Player.h"
#include "CoordsTransformator.h"
#include <iostream>

Player::Player(SDL2pp::Texture &textureCar, SDL2pp::Texture &textureTurbo) : 
    anCar(textureCar), 
    anTurbo(textureTurbo), 
    facingLeft(false), 
    moving(false),
    turbo(false) {}

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
    this->x = newXPosTransformed;
    this->y = newYPosTransformed;
    this->angle = CoordsTransformator::radianToDegree(playerModel.getAngle());
    this->turbo = playerModel.isDoingTurbo();
    this->facingLeft = (playerModel.getFacing() == "left");

}

void Player::render(SDL2pp::Renderer &renderer) {
    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    
    if (not turbo) 
        anCar.render(renderer, SDL2pp::Rect(x, y, CAR_WIDTH, CAR_HEIGHT), flip, angle);
    else
        anTurbo.render(renderer, SDL2pp::Rect(x - 50, y, CAR_WIDTH + 50, CAR_HEIGHT), flip, angle);

    /*
    if (turbo) {
        anTurbo.render(renderer, SDL2pp::Rect(x -CAR_HEIGHT, y,
         CAR_HEIGHT, CAR_HEIGHT), flip, angle);
    }
    */

}

