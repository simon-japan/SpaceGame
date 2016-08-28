//
// Created by SJ Holland on 4/5/16.
//

#include <iostream>
#include "Renderer.h"
#include "../Model/Geometry.h"

using namespace std;

// TODO: take a list of characters and figure out somehow which CharacterSpriteRenderer to use for each one.

void Renderer::renderAll(SDL_Rect& camera, Level & level, vector<Character*> & characters) {

    //Clear screen
    SDL_SetRenderDrawColor( sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( sdlRenderer );

    //cout << "Begin render loop" << endl;
    // TODO: some kind of logging

    GameObjectRenderer * gameObjectRenderer = nullptr;

    //Render tiles from level
    const vector<Tile> & tiles = level.getTiles();
    for( auto & tile : tiles )
    {

        if (rendererRegistry.find(tile.getUUID()) != rendererRegistry.end())
        {
            gameObjectRenderer = &(rendererRegistry[tile.getUUID()]);
        }
        else
        {
            addRendererForModelObject(tile);
        }
        gameObjectRenderer->render(camera, sdlRenderer);

    }

    //Render characters - after all of the tiles, because the characters are on top.
    for (auto character: characters) {
        if (rendererRegistry.find(character->getUUID()) != rendererRegistry.end())
        {
            gameObjectRenderer = &(rendererRegistry[character->getUUID()]);
        }
        else
        {
            addRendererForModelObject(*character);
        }
        gameObjectRenderer->render(camera, sdlRenderer);
    }

    //Update screen
    SDL_RenderPresent( sdlRenderer );

}

void Renderer::addRendererForModelObject(GameObject & subject) {
    gameObjectRendererFactory.createRenderer()
    rendererRegistry.emplace(subject.getUUID(), )
}

void Renderer::addRendererForTile(GameObject & subject) {

}


