//
// Created by SJ Holland on 4/6/16.
//

#ifndef SDTTEST_SPRITE_H
#define SDTTEST_SPRITE_H

#include <vector>
#include "LTexture.h"

class Sprite {

public:
    Sprite(std::string n, LTexture & t): name(n), texture(t) {
        nextClipIndex = 0;
        numberOfClips = 1;
        clipsOffset = 0;
    };

    Sprite(std::string n, LTexture & t, size_t f, size_t l): name(n), texture(t), numberOfClips(f), clipsOffset(l) {};

    void nextFrame();

    void render(const int x, const int y, SDL_Renderer* sdlRenderer);

    std::string getName();

private:
    size_t numberOfClips;
    size_t clipsOffset;
    std::string name;
    size_t nextClipIndex;
    LTexture & texture;
};

#endif //SDTTEST_SPRITE_H

