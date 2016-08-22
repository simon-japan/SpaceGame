//
// Created by SJ Holland on 8/21/16.
//

#include "Clip.h"

void Clip::render(const int x, const int y, SDL_Renderer *sdlRenderer) {
    return texture.render(x, y, sdlRenderer, &dimensions);
}
