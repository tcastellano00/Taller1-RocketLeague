#ifndef SCENE_H
#define SCENE_H
#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#define SCREENWIDTH 1800
#define SCREENHEIGHT 600


class Scene {
private:
    Animation background;
    Animation wallsAndScore;
    
public:
    Scene(SDL2pp::Texture &bkTexture, SDL2pp::Texture &wsTexture);
    void render(SDL2pp::Renderer &renderer);


    ~Scene() = default;
};

#endif
