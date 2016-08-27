//
// Created by SJ Holland on 8/28/16.
//

#ifndef SPACEGAME_CHARACTERRENDERERFACTORY_H
#define SPACEGAME_CHARACTERRENDERERFACTORY_H


#include "GameObjectRenderer.h"
#include "GameObjectRendererFactory.h"
#include "CharacterRenderer.h"

class CharacterRendererFactory: public GameObjectRendererFactory {
public:
    GameObjectRenderer createRenderer() override { return CharacterRenderer(); };
};


#endif //SPACEGAME_CHARACTERRENDERERFACTORY_H
