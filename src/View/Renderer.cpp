//
// Created by SJ Holland on 4/5/16.
//

#include <iostream>
#include "Renderer.h"
#include "../Model/Geometry.h"

using namespace std;

void Renderer::renderAll(SDL_Rect& camera, Level & level, Character & player) {

    //Clear screen
    SDL_SetRenderDrawColor( sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( sdlRenderer );

    //cout << "Begin render loop" << endl;
    // TODO: some kind of logging

    //Render tiles from level
    const vector<Tile> & tiles = level.getTiles();
    for( auto & tile : tiles )
    {

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
    cout << endl;

    //Render player - it must be rendered after all of the tiles
    playerRenderer.render(player, camera, sdlRenderer);

    //Update screen
    SDL_RenderPresent( sdlRenderer );

}





