#include "Player.h"

Player::Player(SDL2pp::Texture &texture): an(texture), facingLeft(false), moving(false), x(100), y(400) {}

Player::~Player() {}

void Player::update(PlayerModel playerModel, int dt) {
    int newXPos = playerModel.getCoordX();

    if (this->x != newXPos) {
        if(newXPos < x){
            facingLeft = true;
        }
        else{
            facingLeft = false;
        }
        an.update(dt);
        this->x = newXPos;

    }
}

void Player::render(SDL2pp::Renderer &renderer) {
    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    an.render(renderer, SDL2pp::Rect(x, y, 183, 53), flip);
}

