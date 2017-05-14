//
// Created by SJ Holland on 8/28/16.
//

#ifndef SPACEGAME_GAMEOBJECTRENDERERFACTORY_H
#define SPACEGAME_GAMEOBJECTRENDERERFACTORY_H


#include "GameObjectRenderer.h"
#include "SpriteRepository.h"
#include "../Model/GameObject.h"
#include "../Model/Tile.h"

class GameObjectRendererFactory {
public:

    enum RENDERER_FACTORIES
    {
        CHARACTER,
        TILE
    };

    //GameObjectRendererFactory(SpriteRepository & s): spriteRepository(s) {};

    virtual std::unique_ptr<GameObjectRenderer> createTileRenderer(const Tile & subject) { return nullptr; };

    virtual std::unique_ptr<GameObjectRenderer> createCharacterRenderer(GameObject & subject) {return nullptr;};

};


#endif //SPACEGAME_GAMEOBJECTRENDERERFACTORY_H
