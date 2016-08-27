//
// Created by SJ Holland on 8/28/16.
//

#include "GameObjectRendererFactory.h"
#include "CharacterRenderer.h"

GameObjectRenderer GameObjectRendererFactory::createRenderer() {
    return CharacterRenderer();
}
