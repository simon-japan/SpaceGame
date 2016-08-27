//
// Created by SJ Holland on 4/5/16.
//

#ifndef SDTTEST_RENDERER_H
#define SDTTEST_RENDERER_H

#include <SDL_system.h>
#include <SDL.h>
#include "LTexture.h"
#include "../Model/Level.h"
#include "../Model/Character.h"
#include "Sprite.h"
#include "SpriteRepository.h"
#include "CharacterRenderer.h"

class Renderer {

public:
    Renderer(SDL_Renderer* r, CharacterRenderer & cr, SpriteRepository & sr): sdlRenderer(r),
                                                                              playerRenderer(cr),
                                                                              spriteRepository(sr){};

    void renderAll(SDL_Rect& camera, Level & level, Character & dot);

private:
    SDL_Renderer * sdlRenderer;

    SpriteRepository & spriteRepository;

    CharacterRenderer & playerRenderer;

};


#endif //SDTTEST_RENDERER_H
