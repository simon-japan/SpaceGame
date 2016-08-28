//
// Created by SJ Holland on 8/27/16.
//

#ifndef SPACEGAME_GAMEOBJECTRENDERER_H
#define SPACEGAME_GAMEOBJECTRENDERER_H


#include <SDL_system.h>
#include "../Model/GameObject.h"

class GameObjectRenderer {
public:
    virtual void render(SDL_Rect camera, SDL_Renderer *sdlRenderer) = 0;
};


#endif //SPACEGAME_GAMEOBJECTRENDERER_H
