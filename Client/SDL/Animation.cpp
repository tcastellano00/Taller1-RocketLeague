/*
 * Created by Federico Manuel Gomez Peter
 * Date: 17/05/18.
 */
#include <SDL2pp/SDL2pp.hh>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

#include "Animation.h"

Animation::Animation(SDL2pp::Texture &texture, int numberRows, int numberColumns) :
    texture(texture),
    currentFrameRow(0),
    currentFrameColumn(0),
    numRows(numberRows),
    numColumns(numberColumns),
    height(this->texture.GetHeight()/numRows),
    width(this->texture.GetWidth()/numColumns),
    elapsed(0.0f) {
    //assert(this->numFrames > 0);
    //assert(this->size > 0);
}


Animation::~Animation() {}

void Animation::update(float dt) {
    this->elapsed += dt;
    /* checks if the frame should be updated based on the time elapsed since the last update */
    while (this->elapsed > FRAME_TIME) {
        this->advanceFrame();
        this->elapsed -= FRAME_TIME;
    }
}

/**
 * @brief Renders the animation in the given coordinates.
 *
 * @param renderer Renderer.
 * @param x X coordinate.
 * @param y Y corrdinate.
 */
void Animation::render(SDL2pp::Renderer &renderer, const SDL2pp::Rect dst, SDL_RendererFlip &flipType, float angle) {
    renderer.Copy(
            texture,
            SDL2pp::Rect(1 + (1 + this->width * this->currentFrameRow), 1 + (1 + this->height * this->currentFrameColumn), this->width, this->height),
            dst,
            angle,
            SDL2pp::NullOpt,    // rotation center - not needed
            flipType
        );
}

void Animation::advanceFrame() {
    this->currentFrameColumn += 1; //Avanzo un frame a la derecha
    if (this->currentFrameColumn == this->numColumns) { //Si estaba en el ultimo de la fila
        this->currentFrameColumn = 0;
        this->currentFrameRow += 1; //Avanzo uno para abajo y vuelvo al primero de la fila
        if (this->currentFrameRow == this->numRows) { //Si estaba en la ultima fila
            this->currentFrameRow = 0; //Vuelvo a la primera fila
        }
    }
}

SDL2pp::Texture& Animation::getTexture() {
    return this->texture;
}
