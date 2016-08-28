//
// Created by SJ Holland on 8/28/16.
//

#ifndef SPACEGAME_TILERENDERER_H
#define SPACEGAME_TILERENDERER_H


#include <SDL_rect.h>
#include <SDL_system.h>
#include "../Model/Tile.h"
#include "GameObjectRenderer.h"
#include "Sprite.h"

class TileSpriteRenderer: public GameObjectRenderer {
public:
    TileSpriteRenderer(const Tile & t, Sprite & s): tile(t), sprite(s) {};
    void render(SDL_Rect camera, SDL_Renderer *sdlRenderer) override;

private:
    const Tile & tile;
    Sprite & sprite; // Todo: I imagine that there could be several sprites to a tile, e.g. different levels of damage
};


#endif //SPACEGAME_TILERENDERER_H
