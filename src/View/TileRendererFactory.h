//
// Created by SJ Holland on 8/28/16.
//

#ifndef SPACEGAME_TILERENDERERFACTORY_H
#define SPACEGAME_TILERENDERERFACTORY_H


#include "GameObjectRenderer.h"
#include "TileRenderer.h"

class TileRendererFactory {
public:
    GameObjectRenderer createRenderer() override { return TileRenderer(); };
};


#endif //SPACEGAME_TILERENDERERFACTORY_H
