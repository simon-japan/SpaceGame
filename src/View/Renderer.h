//
// Created by SJ Holland on 4/5/16.
//

#ifndef SDTTEST_RENDERER_H
#define SDTTEST_RENDERER_H

#include <SDL_system.h>
#include <SDL.h>
#include <unordered_map>
#include "LTexture.h"
#include "../Model/Level.h"
#include "../Model/Character.h"
#include "Sprite.h"
#include "SpriteRepository.h"
#include "CharacterRenderer.h"
#include <boost/functional/hash.hpp>

class Renderer {

public:
    Renderer(SDL_Renderer* r, SpriteRepository & sr): sdlRenderer(r), spriteRepository(sr){};

    void renderAll(SDL_Rect& camera, Level & level, std::vector<Character*> & characters);

private:
    SDL_Renderer * sdlRenderer;

    SpriteRepository & spriteRepository;

    std::unordered_map<boost::uuids::uuid, GameObjectRenderer *, boost::hash<boost::uuids::uuid>> rendererRegistry;
};


#endif //SDTTEST_RENDERER_H
