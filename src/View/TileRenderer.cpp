//
// Created by SJ Holland on 8/28/16.
//

#include "TileRenderer.h"
#include "../Model/Tile.h"
#include "Sprite.h"
#include "../Model/Geometry.h"

void TileRenderer::render(SDL_Rect camera, SDL_Renderer *sdlRenderer) {
    SDL_Rect box = tile.getCollisionBox();

    // Only render the tile if it's in-camera
    if (Geometry::checkCollision(box, camera))
    {
        // Look up which sprite to use, from the map of registered sprites,
        // based on the string provided by the Tile to identify its visual type.
        Sprite * sprite = spriteRepository.getSprite(tile.getTypeName());

        // Render the sprite at the tile's absolute location, modified by the position of the camera.
        SDL_Rect target;
        target.x = box.x - camera.x;
        target.y = box.y - camera.y;
        target.w = TILE_WIDTH;
        target.h = TILE_HEIGHT;
        sprite->render(target, 0, sdlRenderer);

        //cout << "Rendered tile: " << box.x << "," << box.y << endl;
    }
    else
    {
        //cout << "Did not render tile outside camera: " << box.x << "," << box.y << endl;
    }
}
