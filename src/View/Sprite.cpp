//
// Created by SJ Holland on 4/6/16.
//

#include "Sprite.h"

void Sprite::render(const int x, const int y, SDL_Renderer* sdlRenderer) {
    texture.renderClipByIndex(x, y, sdlRenderer, clipsOffset + nextClipIndex);
}

void Sprite::nextFrame() {
    nextClipIndex = nextClipIndex < numberOfClips - 1 ? nextClipIndex + 1 : 0;
}

std::string Sprite::getName() {
    return name;
}









