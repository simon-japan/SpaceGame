//
// Created by SJ Holland on 4/6/16.
//

#include <iostream>
#include "Sprite.h"

void Sprite::render(const int x, const int y, SDL_Renderer *sdlRenderer) {
    clips[nextClipIndex].render(x, y, sdlRenderer);
}

void Sprite::render(SDL_Rect & target, SDL_Renderer *sdlRenderer) {
    clips[nextClipIndex].render(target, sdlRenderer);
}

void Sprite::nextAnimationFrame() {
    nextClipIndex = nextClipIndex < clips.size() - 1 ? nextClipIndex + 1 : 0;
}

const std::string Sprite::getName() const{
    return name;
}

void Sprite::addClip(LTexture & texture, int x, int y, int w, int h) {
    SDL_Rect clip;
    clip.x = x;
    clip.y = y;
    clip.w = w;
    clip.h = h;
    clips.emplace_back(texture, clip);
}










