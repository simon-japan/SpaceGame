//
// Created by SJ Holland on 8/27/16.
//

#ifndef SPACEGAME_CHARACTERRENDERER_H
#define SPACEGAME_CHARACTERRENDERER_H


#include <SDL_system.h>
#include "../Model/Character.h"
#include "SpriteRepository.h"

class CharacterRenderer {
public:
    CharacterRenderer(Sprite & sl, Sprite & wl, Sprite & sr, Sprite & wr): standingLeftSprite(sl),
                                                                           walkingLeftSprite(wl),
                                                                           standingRightSprite(sr),
                                                                           walkingRightSprite(wr),
                                                                           animationState(0){};

    void render(Character character, SDL_Rect camera, SDL_Renderer *sdlRenderer);

private:
    Sprite & standingLeftSprite;
    Sprite & walkingLeftSprite;
    Sprite & standingRightSprite;
    Sprite & walkingRightSprite;

    int animationState;

};

// TODO: make this a base class so that animation behavior can be customized based on the type of character
// TODO: make the set of sprites passed in a bit more abstract, eg a map istead of just 4 pointers
// TODO: make a factory that builds these based on configuration

#endif //SPACEGAME_CHARACTERRENDERER_H
