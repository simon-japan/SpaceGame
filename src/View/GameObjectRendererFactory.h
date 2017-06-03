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

    GameObjectRendererFactory(SpriteRepository & s): spriteRepository(s) {};

    std::unique_ptr<GameObjectRenderer> createGameObjectRenderer(GameObject & subject);

private:
    SpriteRepository & spriteRepository;
};


#endif //SPACEGAME_GAMEOBJECTRENDERERFACTORY_H
