//
// Created by SJ Holland on 4/6/16.
//

#include "Sprite.h"

void Sprite::render(const int x, const int y, SDL_Renderer* gRenderer) {
    sheet.render(x, y, gRenderer, name);
}



