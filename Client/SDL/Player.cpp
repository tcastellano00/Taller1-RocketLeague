#include "Player.h"

Player::Player(SDL2pp::Texture &texture): an(texture), facingLeft(false), moving(false), x(300), y(300) {}

Player::~Player() {}

//Aca deberiamos enviar PlayerModel
void Player::update(int newXPos, int dt) {
    //int newXPos = playerModel.getCoordX();

    if (this->x != newXPos) {
        an.update(dt);
        this->x = newXPos;
    }
}

void Player::render(SDL2pp::Renderer &renderer) {
    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    an.render(renderer, SDL2pp::Rect(x, y, 200, 200), flip);
}

