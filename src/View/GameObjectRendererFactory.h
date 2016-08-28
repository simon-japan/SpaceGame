//
// Created by SJ Holland on 8/28/16.
//

#ifndef SPACEGAME_GAMEOBJECTRENDERERFACTORY_H
#define SPACEGAME_GAMEOBJECTRENDERERFACTORY_H


#include "GameObjectRenderer.h"
#include "SpriteRepository.h"
#include "../Model/Character.h"

class GameObjectRendererFactory {
public:

    enum RENDERER_FACTORIES
    {
        CHARACTER,
        TILE
    };

    //GameObjectRendererFactory(SpriteRepository & s): spriteRepository(s) {};

    virtual GameObjectRenderer createTileRenderer(Tile & subject) = delete;

    virtual GameObjectRenderer createCharacterRenderer(Character & subject) = delete;

};


#endif //SPACEGAME_GAMEOBJECTRENDERERFACTORY_H
