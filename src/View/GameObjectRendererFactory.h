//
// Created by SJ Holland on 8/28/16.
//

#ifndef SPACEGAME_GAMEOBJECTRENDERERFACTORY_H
#define SPACEGAME_GAMEOBJECTRENDERERFACTORY_H


#include "GameObjectRenderer.h"

class GameObjectRendererFactory {
public:
    virtual GameObjectRenderer createRenderer();
};


#endif //SPACEGAME_GAMEOBJECTRENDERERFACTORY_H
