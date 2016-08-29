//
// Created by SJ Holland on 8/21/16.
//

#ifndef SPACEGAME_CLIP_H
#define SPACEGAME_CLIP_H


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


#endif //SPACEGAME_CLIP_H
