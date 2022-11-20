#include "Score.h"

Score::Score(
        SDL2pp::Texture &zeroTexture,
        SDL2pp::Texture &oneTexture,
        SDL2pp::Texture &twoTexture,
        SDL2pp::Texture &threeTexture,
        SDL2pp::Texture &fourTexture,
        SDL2pp::Texture &fiveTexture,
        SDL2pp::Texture &sixTexture,
        SDL2pp::Texture &sevenTexture,
        SDL2pp::Texture &eightTexture,
        SDL2pp::Texture &nineTexture) {

            /*numbersAnimation.emplace_back(zeroTexture);
            numbersAnimation.emplace_back(oneTexture);
            numbersAnimation.emplace_back(twoTexture);
            numbersAnimation.emplace_back(threeTexture);
            numbersAnimation.emplace_back(fourTexture);
            numbersAnimation.emplace_back(fiveTexture);
            numbersAnimation.emplace_back(sixTexture);
            numbersAnimation.emplace_back(sevenTexture);
            numbersAnimation.emplace_back(eightTexture);
            numbersAnimation.emplace_back(nineTexture);*/
            vectorNumberAnimations.emplace_back(zeroTexture);
            vectorNumberAnimations.emplace_back(oneTexture);
            vectorNumberAnimations.emplace_back(twoTexture);
            vectorNumberAnimations.emplace_back(threeTexture);
            vectorNumberAnimations.emplace_back(fourTexture);
            vectorNumberAnimations.emplace_back(fiveTexture);
            vectorNumberAnimations.emplace_back(sixTexture);
            vectorNumberAnimations.emplace_back(sevenTexture);
            vectorNumberAnimations.emplace_back(eightTexture);
            vectorNumberAnimations.emplace_back(nineTexture);
}

void Score::update(ScoreModel scoreModel, int dt) {
    this->numberOfGoalsLeft = scoreModel.getGoalsFirstTeam();
    this->numberOfGoalsRight = scoreModel.getGoalsSecondTeam();

    /*auto firstIndex = this->numbersAnimation.begin();
    std::advance(firstIndex, this->numberOfGoalsLeft);
    firstIndex->update(dt);

    auto secIndex = this->numbersAnimation.begin();
    std::advance(secIndex, this->numberOfGoalsRight);
    secIndex->update(dt);*/
    vectorNumberAnimations[this->numberOfGoalsLeft].update(dt);
    vectorNumberAnimations[this->numberOfGoalsRight].update(dt);
}

void Score::render(SDL2pp::Renderer &renderer){
    //SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    /*auto firstIndex = this->numbersAnimation.begin();
    std::advance(firstIndex, this->numberOfGoalsLeft);
    firstIndex->render(renderer, SDL2pp::Rect(810, 30, 40, 60),flip, 0);

    auto secIndex = this->numbersAnimation.begin();
    std::advance(secIndex, this->numberOfGoalsRight);
    secIndex->render(renderer, SDL2pp::Rect(960, 30, 40, 60),flip, 0);*/

    vectorNumberAnimations[this->numberOfGoalsLeft].render(renderer, SDL2pp::Rect(810, 30, 40, 60),flip, 0);
    vectorNumberAnimations[this->numberOfGoalsRight].render(renderer, SDL2pp::Rect(960, 30, 40, 60),flip, 0);

    


}