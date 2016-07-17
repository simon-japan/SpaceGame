//
// Created by SJ Holland on 4/6/16.
//

#include <iostream>
#include "Sprite.h"

void Sprite::render(const int x, const int y, SDL_Renderer* sdlRenderer) {
    //std::cout << "Sprite::render - clipsOffset:" << clipsOffset << ", nextClipIndex: " << nextClipIndex << std::endl;
    texture.renderClipByIndex(x, y, sdlRenderer, clipsOffset + nextClipIndex);
}

void Sprite::nextFrame() {
    nextClipIndex = nextClipIndex < numberOfClips - 1 ? nextClipIndex + 1 : 0;
}

const std::string Sprite::getName() const{
    return name;
}









