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
            sprite->render(target, sdlRenderer);

            //cout << "Rendered tile: " << box.x << "," << box.y << endl;
        }
        else
        {
            //cout << "Did not render tile outside camera: " << box.x << "," << box.y << endl;
        }

    }
    cout << endl;


    //Render player - it must be rendered after all of the tiles
    SDL_Rect playerBox = player.getCollisionBox();
    Sprite * playerSprite = nullptr;
    if (player.getXVelocity() || player.getYVelocity())
    {
        if (player.getDirection() == Direction::right) {
            playerSprite = spriteRepository.getSprite("spaceman_walking_right");
        }
        else
        {
            playerSprite = spriteRepository.getSprite("spaceman_walking_left");
        }
    }
    else
    {
        if (player.getDirection() == Direction::right)
        {
            playerSprite = spriteRepository.getSprite("spaceman_standing_right");
        }
        else
        {
            playerSprite = spriteRepository.getSprite("spaceman_standing_left");
        }

    }
    playerSprite->render(playerBox.x - camera.x, playerBox.y - camera.y, sdlRenderer);

    // I'm treating the animation state as being a part of the view
    if (player.getXVelocity() || player.getYVelocity())
    {
        playerSprite->nextAnimationFrame(); // If the sprite is animated, continue the animation loop
    }

    //Update screen
    SDL_RenderPresent( sdlRenderer );

}





