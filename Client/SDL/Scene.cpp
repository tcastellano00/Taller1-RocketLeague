#include "Scene.h"


Scene::Scene(SDL2pp::Texture &bkTexture, SDL2pp::Texture &wsTexture): background(bkTexture), wallsAndScore(wsTexture) {}

void Scene::render(SDL2pp::Renderer &renderer) {
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    background.render(renderer, SDL2pp::Rect(0, 0, SCREENWIDTH, SCREENHEIGHT),flip, 0);
    wallsAndScore.render(renderer, SDL2pp::Rect(0, 0, SCREENWIDTH, SCREENHEIGHT),flip, 0);
}