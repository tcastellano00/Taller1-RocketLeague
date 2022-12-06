#include "Score.h"
#include "DigitSeparator.h"



#include <iostream>

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
        SDL2pp::Texture &nineTexture,
        SDL2pp::Texture &colon,
        SDL2pp::Texture &scoreTexture): colon(colon, 1, 1), anScoreBox(scoreTexture, 1, 1) {
            vectorNumberAnimations.emplace_back(zeroTexture, 1, 1);
            vectorNumberAnimations.emplace_back(oneTexture, 1, 1);
            vectorNumberAnimations.emplace_back(twoTexture, 1, 1);
            vectorNumberAnimations.emplace_back(threeTexture, 1, 1);
            vectorNumberAnimations.emplace_back(fourTexture, 1, 1);
            vectorNumberAnimations.emplace_back(fiveTexture, 1, 1);
            vectorNumberAnimations.emplace_back(sixTexture, 1, 1);
            vectorNumberAnimations.emplace_back(sevenTexture, 1, 1);
            vectorNumberAnimations.emplace_back(eightTexture, 1, 1);
            vectorNumberAnimations.emplace_back(nineTexture, 1, 1);
}

void Score::update(ScoreModel scoreModel, int dt) {
    this->numberOfGoalsLeft = scoreModel.getGoalsFirstTeam();
    this->numberOfGoalsRight = scoreModel.getGoalsSecondTeam();
    this->minutesLeft = scoreModel.getMinutesLeft();
    this->secondsLeft = scoreModel.getSecondsLeft();
    this->milisecondsLeft = scoreModel.getMiliSecondsLeft();

    //std::cout << this->minutesLeft << "   " << this->secondsLeft << std::endl;



    for (int i = 0; i < 10; i++) {
        vectorNumberAnimations[i].update(dt);
    }
    colon.update(dt);
    anScoreBox.update(dt);

}

void Score::render(SDL2pp::Renderer &renderer){
    //SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    //vectorNumberAnimations[this->numberOfGoalsLeft].render(renderer, SDL2pp::Rect(810, 30, 40, 60),flip, 0);
    //vectorNumberAnimations[this->numberOfGoalsRight].render(renderer, SDL2pp::Rect(960, 30, 40, 60),flip, 0);


    anScoreBox.render(renderer, SDL2pp::Rect(FIRSTDIGITLEFTPOSX  - NUMBERWIDTH/4, DIGITPOSY - NUMBERHEIGHT/4, NUMBERWIDTH*7, NUMBERHEIGHT*2), flip, 0);

    std::vector<int> digitsGoalsLeft(DigitSeparator::getVectorOfDigits(numberOfGoalsLeft));
    for (int i = 0; i < (int)digitsGoalsLeft.size(); ++i) {
        if (i == 0 && digitsGoalsLeft[0] == 0 && (int)digitsGoalsLeft.size() != 0) {
            continue;
        }
        vectorNumberAnimations[digitsGoalsLeft[i]].render(renderer, SDL2pp::Rect(FIRSTDIGITLEFTPOSX + i*(NUMBERWIDTH + NUMBERSPACE), DIGITPOSY, NUMBERWIDTH, NUMBERHEIGHT), flip, 0);
    }

    std::vector<int> digitsGoalsRight(DigitSeparator::getVectorOfDigits(numberOfGoalsRight));
    for (int i = 0; i < (int)digitsGoalsRight.size(); ++i) {
        if (i == 0 && digitsGoalsLeft[0] == 0 && (int)digitsGoalsLeft.size() != 0) {
            continue;
        }
        vectorNumberAnimations[digitsGoalsRight[i]].render(renderer, SDL2pp::Rect(FIRSTDIGITRIGHTPOSX + i*(NUMBERWIDTH + NUMBERSPACE), DIGITPOSY, NUMBERWIDTH, NUMBERHEIGHT), flip, 0);
    }

    std::vector<int> digitsMinutes(DigitSeparator::getVectorOfDigits(minutesLeft));
    for (int i = 0; i < (int)digitsMinutes.size(); ++i) {
        vectorNumberAnimations[digitsMinutes[i]].render(renderer, SDL2pp::Rect(MINUTESPOSX + i*(TIMEWIDTH + NUMBERSPACE), TIMEPOSY, TIMEWIDTH, TIMEHEIGHT), flip, 0);
    }

    std::vector<int> digitsSeconds(DigitSeparator::getVectorOfDigits(secondsLeft));
    for (int i = 0; i < (int)digitsSeconds.size(); ++i) {
        vectorNumberAnimations[digitsSeconds[i]].render(renderer, SDL2pp::Rect(SECSPOSX + i*(TIMEWIDTH + NUMBERSPACE), TIMEPOSY, TIMEWIDTH, TIMEHEIGHT), flip, 0);
    }
    colon.render(renderer, SDL2pp::Rect(COLONPOSX, TIMEPOSY, TIMEWIDTH, TIMEHEIGHT), flip, 0);

}