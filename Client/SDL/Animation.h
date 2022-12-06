#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <SDL2pp/SDL2pp.hh>

class SdlTexture;
class Area;


/*
Guarda a la textura correspondiente y encapsula el comportamiento de "avanzar" cuadros de
un sprite compuesto por varios cuadros, que al imprimirlos secuencialmente se forma la animacion.
*/
class Animation {
   public:
    Animation(SDL2pp::Texture &texture, int numberRows, int numberColumns);
    ~Animation();
    bool update(float dt);
    void render(SDL2pp::Renderer &renderer, const SDL2pp::Rect dest, SDL_RendererFlip &flipType, float angle);

    SDL2pp::Texture& getTexture();


   private:
    bool advanceFrame();
    /** SDL texture of the raw image. */
    SDL2pp::Texture &texture;
    /** Current animation frame's row. */
    int currentFrameRow;
    /** Current animation frame's column. */
    int currentFrameColumn;
    /** Total number of rows in the sprite. */
    int numRows;
    /** Total number of columns in the sprite. */
    int numColumns;
    /** Height of the sprite. */
    int height;
    /* Width of the sprite*/
    int width;
    /** Time elapsed since last update. */
    float elapsed;
};

#endif  //__ANIMATION_H__
