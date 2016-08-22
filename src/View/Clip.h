//
// Created by SJ Holland on 8/21/16.
//

#ifndef SDTTEST_CLIP_H
#define SDTTEST_CLIP_H


#include "LTexture.h"

class Clip {
public:
    Clip(LTexture & t, SDL_Rect d): texture(t), dimensions(d){}

    void render(const int x, const int y, SDL_Renderer* sdlRenderer);

private:
    LTexture & texture;
    SDL_Rect dimensions;
};


#endif //SDTTEST_CLIP_H
