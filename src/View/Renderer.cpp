//
// Created by SJ Holland on 4/5/16.
//

#include <iostream>
#include "Renderer.h"
#include "../Model/Geometry.h"

using namespace std;

void Renderer::renderAll(SDL_Rect& camera, Level & level, Dot & dot) {

    //Clear screen
    SDL_SetRenderDrawColor( sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( sdlRenderer );

    cout << "Begin render loop" << endl;

    //Render tiles from level
    const vector<Tile> & tiles = level.getTiles();
    for( auto & tile : tiles )
    {
        cout << "\nattempting to render tile: " << tile << endl;

        SDL_Rect box = tile.getCollisionBox();

        // Only render the tile if it's in-camera
        if (Geometry::checkCollision(box, camera))
        {
            // Look up which sprite to use, from the map of registered sprites,
            // based on the string provided by the Tile to identify its visual type.
            string tileTypeName (tile.getTypeName());
            Sprite & sprite = spriteRepository.getSprite(tileTypeName);

            cout << "attempting to render sprite: " << sprite << endl;

            // Render the sprite at the tile's absolute location, modified by the position of the camera.
            sprite.render(box.x - camera.x, box.y - camera.y, sdlRenderer);
        }
        else
        {
            cout << "Did not render tile outiside camera: " << box.x << "," << box.y << endl;
        }

    }
    cout << endl;


    //Render dot - it must be rendered after all of the tiles
    SDL_Rect dotBox = dot.getCollisionBox();
    Sprite & dotSprite = spriteRepository.getSprite("dot");
    dotSprite.render(dotBox.x - camera.x, dotBox.y - camera.y, sdlRenderer);

    //Update screen
    SDL_RenderPresent( sdlRenderer );

}





