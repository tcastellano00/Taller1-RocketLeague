#include "Player.h"
#include "CoordsTransformator.h"

Player::Player(SDL2pp::Texture &texture): an(texture), facingLeft(false), moving(false), x(100), y(400), angle(0) {}

Player::~Player() {}

void Player::update(PlayerModel playerModel, int dt) {
    float newXPos = playerModel.getCoordX();
    float newYpos = playerModel.getCoordY();

    float newXPosTransformed = CoordsTransformator::transformX(newXPos);
    float newYPosTransformed = CoordsTransformator::transformY(newYpos);


    if(newXPosTransformed < x){
        facingLeft = true;
    }
    else{
        facingLeft = false;
    }
    an.update(dt);
    this->x = newXPosTransformed;
    this->y = newYPosTransformed;
    this->angle = CoordsTransformator::radianToDegree(playerModel.getAngle());

}

void Player::render(SDL2pp::Renderer &renderer) {
    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    an.render(renderer, SDL2pp::Rect(x, y, 200, 40), flip, angle);
}

