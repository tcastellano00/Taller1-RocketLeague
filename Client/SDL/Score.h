#ifndef SCORE_H
#define SCORE_H

#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include <list>
#include "../../Common/Model/ScoreModel.h"
#include <vector>

class Score {
private:
    std::list<Animation> numbersAnimation;
    int numberOfGoalsLeft;
    int numberOfGoalsRight;
    std::vector<Animation> vectorNumberAnimations;
    
public:
    Score(
        SDL2pp::Texture &zeroTexture,
        SDL2pp::Texture &oneTexture,
        SDL2pp::Texture &twoTexture,
        SDL2pp::Texture &threeTexture,
        SDL2pp::Texture &fourTexture,
        SDL2pp::Texture &fiveTexture,
        SDL2pp::Texture &sixTexture,
        SDL2pp::Texture &sevenTexture,
        SDL2pp::Texture &eightTexture,
        SDL2pp::Texture &nineTexture
    );

    void update(ScoreModel scoreModel, int dt);
    void render(SDL2pp::Renderer &renderer);


    ~Score() = default;
};

#endif