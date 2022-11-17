#include "Player.h"
#include "CoordsTransformator.h"

Player::Player(SDL2pp::Texture &texture): an(texture), facingLeft(false), moving(false), x(100), y(400) {}

Player::~Player() {}

void Player::update(PlayerModel playerModel, int dt) {
    float newXPos = playerModel.getCoordX();
    float newYpos = playerModel.getCoordY();

    float newXPosTransformed = CoordsTransformator::transformX(newXPos);
    float newYPosTransformed = CoordsTransformator::transformY(newYpos);


    if (this->x != newXPosTransformed) {
        if(newXPosTransformed < x){
            facingLeft = true;
        }
        else{
            facingLeft = false;
        }
        an.update(dt);
        this->x = newXPosTransformed;
        this->y = newYPosTransformed;

    }
}

void Player::render(SDL2pp::Renderer &renderer) {
    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    an.render(renderer, SDL2pp::Rect(x, y, 183, 53), flip);
}

