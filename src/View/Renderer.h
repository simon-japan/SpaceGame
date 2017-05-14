//
// Created by SJ Holland on 4/5/16.
//

#ifndef SPACEGAME_RENDERER_H
#define SPACEGAME_RENDERER_H

#include <SDL_system.h>
#include <SDL.h>
#include <unordered_map>
#include "GameTexture.h"
#include "../Model/Level.h"
#include "../Model/GameObject.h"
#include "Sprite.h"
#include "SpriteRepository.h"
#include "CharacterSpriteRenderer.h"
#include "GameObjectRendererFactory.h"
#include "SpriteRendererFactory.h"
#include <boost/functional/hash.hpp>

class Renderer {

public:
    Renderer(SDL_Renderer* r, SpriteRepository & sr): sdlRenderer(r), spriteRendererFactory(sr){};

    void renderLevel(SDL_Rect & camera, Level & level);

private:
    SDL_Renderer * sdlRenderer;

    SpriteRendererFactory spriteRendererFactory;

    std::unordered_map<boost::uuids::uuid, std::unique_ptr<GameObjectRenderer>, boost::hash<boost::uuids::uuid>> rendererRegistry;

    void addCharacterSpriteRenderer(GameObject & subject);

    void addTileSpriteRenderer(const Tile & subject);
};


#endif //SPACEGAME_RENDERER_H
