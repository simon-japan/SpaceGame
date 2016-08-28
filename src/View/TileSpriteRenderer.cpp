//
// Created by SJ Holland on 8/28/16.
//

#include "TileSpriteRenderer.h"
#include "../Model/Tile.h"
#include "Sprite.h"
#include "../Model/Geometry.h"

void TileSpriteRenderer::render(SDL_Rect camera, SDL_Renderer *sdlRenderer) {
    SDL_Rect box = tile.getCollisionBox();

    // Only render the tile if it's in-camera
    if (Geometry::checkCollision(box, camera))
    {

        // Render the sprite at the tile's absolute location, modified by the position of the camera.
        SDL_Rect target;
        target.x = box.x - camera.x;
        target.y = box.y - camera.y;
        target.w = TILE_WIDTH;
        target.h = TILE_HEIGHT;
        sprite.render(target, 0, sdlRenderer);

        //cout << "Rendered tile: " << box.x << "," << box.y << endl;
    }
    else
    {
        //cout << "Did not render tile outside camera: " << box.x << "," << box.y << endl;
    }
}
