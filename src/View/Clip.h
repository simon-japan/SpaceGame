//
// Created by SJ Holland on 8/21/16.
//

#ifndef SDTTEST_CLIP_H
#define SDTTEST_CLIP_H


#include "GameTexture.h"

class Clip {
public:
    Clip(GameTexture & t, SDL_Rect d): texture(t), dimensions(d){}

    void render(const int x, const int y, SDL_Renderer* sdlRenderer);

    void render(SDL_Rect & target, SDL_Renderer* sdlRenderer);

private:
    GameTexture & texture;
    SDL_Rect dimensions;
};


#endif //SDTTEST_CLIP_H
