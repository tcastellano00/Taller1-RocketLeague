#ifndef SCENE_H
#define SCENE_H
#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include "../../Common/Config/ClientConfig.h"


class Scene {
private:
    Animation background;
    Animation wallsAndScore;

    float SCREENWIDTH = ClientConfig::getScreenWidth();
    float SCREENHEIGHT = SCREENWIDTH/3;
    
public:
    Scene(SDL2pp::Texture &bkTexture, SDL2pp::Texture &wsTexture);
    void render(SDL2pp::Renderer &renderer);


    ~Scene() = default;
};

#endif
