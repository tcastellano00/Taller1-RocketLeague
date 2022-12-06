#ifndef SCORE_H
#define SCORE_H

#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include <list>
#include "../../Common/Model/ScoreModel.h"
#include <vector>
#include "../../Common/Config/ClientConfig.h"

/*
Encargada de imprimir en la ventana de SDL al marcador.
*/
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
    float SCREENWIDTH = ClientConfig::getScreenWidth();
    float SCREENHEIGHT = SCREENWIDTH/3;
    float NUMBERWIDTH = SCREENWIDTH/45;
    float NUMBERHEIGHT = SCREENHEIGHT/10;
    float NUMBERSPACE = SCREENWIDTH/360;
    float FIRSTDIGITLEFTPOSX = SCREENWIDTH/2.3;
    float FIRSTDIGITRIGHTPOSX = SCREENWIDTH/1.93;
    float DIGITPOSY = SCREENHEIGHT/22.22;
    float MINUTESPOSX = SCREENWIDTH/2.2;
    float SECSPOSX = SCREENWIDTH/1.9;
    float TIMEPOSY = SCREENHEIGHT/7.2;
    float TIMEHEIGHT = SCREENHEIGHT/15;
    float TIMEWIDTH = SCREENWIDTH/75;
    float COLONPOSX = SCREENWIDTH/2.02;
    
    
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