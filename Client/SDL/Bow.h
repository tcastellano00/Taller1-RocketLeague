#ifndef BOW_H
#define BOW_H
#include <SDL2pp/SDL2pp.hh>
#include "Animation.h"
#include "../../Common/Model/PlayerModel.h"

// El "arco" de fútbol se traduce más a "goal" que a "bow"
class Bow{
    Animation an;
    int x;
    int y;
    bool facingLeft;

    public:
    Bow(SDL2pp::Texture &texture, int coordX,bool left);
    //void update(int newXPos, int dt);
    void render(SDL2pp::Renderer &renderer);

    ~Bow();
};

#endif