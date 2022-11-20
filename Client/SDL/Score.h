#ifndef SCORE_H
#define SCORE_H

#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include <list>
#include "../../Common/Model/ScoreModel.h"
#include <vector>

class Score {
private:
    int numberOfGoalsLeft;
    int numberOfGoalsRight;
    int minutesLeft;
    int secondsLeft;
    int milisecondsLeft;
    //Almacena las animacionesd e los numeros del 0 al 9, no acceder mas alla del 9 al vector porque da segfault
    std::vector<Animation> vectorNumberAnimations;
    Animation colon;
    
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
        SDL2pp::Texture &nineTexture,
        SDL2pp::Texture &colon
    );

    void update(ScoreModel scoreModel, int dt);
    void render(SDL2pp::Renderer &renderer);


    ~Score() = default;
};

#endif