#include "Player.h"

#include <iostream>

Player::Player(SDL2pp::Texture &textureCar, SDL2pp::Texture &textureTurbo, SDL2pp::Texture &textureTurboBarEmpty, 
    SDL2pp::Texture &textureTurboBarFull,SDL2pp::Texture &turnLeft,SDL2pp::Texture &turnRight,SDL2pp::Texture &humo) : 
    anCar(textureCar, 1, 1), 
    anTurbo(textureTurbo, 1, 1),
    anTurboBarEmpty(textureTurboBarEmpty, 1, 1),
    anTurboBarFull(textureTurboBarFull, 1, 1),
    anTurnLeft(turnLeft,2,4),
    anTurnRight(turnRight,2,4),
    anHumo(humo,5,6),
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
    this->faceTurned = false;

    if (this->face != "")
        this->faceTurned = (playerModel.getFacing() != this->face);
    
    this->face = playerModel.getFacing();
}

void Player::render(SDL2pp::Renderer &renderer, int i) {
    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;


    if(face == "left" && faceTurned){
        anTurnRight.render(renderer,SDL2pp::Rect(x, y, CAR_WIDTH, CAR_HEIGHT), flip, angle);
    }

    if(face != "left" && faceTurned){
        anTurnLeft.render(renderer,SDL2pp::Rect(x, y, CAR_WIDTH, CAR_HEIGHT), flip, angle);
    }
    
    
    if (not turbo){ 
        anCar.render(renderer, SDL2pp::Rect(x, y, CAR_WIDTH, CAR_HEIGHT), flip, angle);
        }
    else{
        anTurbo.render(renderer, SDL2pp::Rect(x - CAR_WIDTH/2, y, CAR_WIDTH + CAR_WIDTH/2, CAR_HEIGHT), flip, angle);
        if(facingLeft){
            anHumo.render(renderer,SDL2pp::Rect(x + CAR_WIDTH, y, CAR_WIDTH , CAR_HEIGHT), flip, angle);
        }else{
            anHumo.render(renderer,SDL2pp::Rect(x - CAR_WIDTH*2, y, CAR_WIDTH , CAR_HEIGHT), flip, angle);
        }
    }
    
    
    flip = SDL_FLIP_NONE;
    if (i == 0) {
        anCar.getTexture().SetColorMod(255, 0, 0);
        float barPercentage = turboRemaining/MAXTURBO;
        anTurboBarFull.render(renderer, SDL2pp::Rect(TURBOBARX, TURBOBARY, TURBOBARWIDTH * barPercentage, TURBOBARHEIGHT), flip, 0);
        anTurboBarEmpty.render(renderer, SDL2pp::Rect(TURBOBARX, TURBOBARY, TURBOBARWIDTH, TURBOBARHEIGHT), flip, 0);
    } else if (i == 1) {
        anCar.getTexture().SetColorMod(0, 0, 255);
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

