//
// Created by SJ Holland on 8/28/16.
//

#ifndef SPACEGAME_TILERENDERER_H
#define SPACEGAME_TILERENDERER_H


#include <SDL_rect.h>
#include <SDL_system.h>
#include "../Model/Tile.h"
#include "GameObjectRenderer.h"

class TileRenderer: public GameObjectRenderer {
public:
    TileRenderer(Tile & t): tile(t) {};
    void render(SDL_Rect camera, SDL_Renderer *sdlRenderer) override;

private:
    Tile & tile;
};


#endif //SPACEGAME_TILERENDERER_H
