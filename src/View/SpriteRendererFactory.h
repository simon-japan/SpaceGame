//
// Created by SJ Holland on 8/28/16.
//

#ifndef SPACEGAME_CHARACTERRENDERERFACTORY_H
#define SPACEGAME_CHARACTERRENDERERFACTORY_H


#include "GameObjectRenderer.h"
#include "GameObjectRendererFactory.h"
#include "CharacterSpriteRenderer.h"
#include "TileSpriteRenderer.h"

class SpriteRendererFactory: public GameObjectRendererFactory {
public:
    SpriteRendererFactory(SpriteRepository & s): spriteRepository(s) {};

    GameObjectRenderer createCharacterRenderer(Character & subject) override;

    GameObjectRenderer createTileRenderer(Tile & subject) override;

private:
    SpriteRepository & spriteRepository;
};


#endif //SPACEGAME_CHARACTERRENDERERFACTORY_H
