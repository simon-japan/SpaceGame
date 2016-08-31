//
// Created by SJ Holland on 4/5/16.
//

#include <iostream>
#include "Renderer.h"
#include "../Model/Geometry.h"

using namespace std;

void Renderer::renderLevel(SDL_Rect & camera, Level & level) {

    //Clear screen
    SDL_SetRenderDrawColor( sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( sdlRenderer );

    //cout << "Begin render loop" << endl;
    // TODO: some kind of logging

    GameObjectRenderer * gameObjectRenderer = nullptr;

    //Render tiles from level
    const vector<Tile> & tiles = level.getTiles();
    for( const auto & tile : tiles )
    {
        if (rendererRegistry.find(tile.getUUID()) == rendererRegistry.end())
        {
            addTileSpriteRenderer(tile);
        }
        gameObjectRenderer = &*rendererRegistry[tile.getUUID()];
        gameObjectRenderer->render(camera, sdlRenderer);

    }

    //Render characters - after all of the tiles, because the characters are on top.
    for (auto it = level.beginCharacters(); it != level.endCharacters(); it++) {

        if (rendererRegistry.find(it->second->getUUID()) == rendererRegistry.end())
        {
            addCharacterSpriteRenderer(*it->second);
        }
        gameObjectRenderer = &*rendererRegistry[it->second->getUUID()];
        gameObjectRenderer->render(camera, sdlRenderer);
    }

    //Update screen
    SDL_RenderPresent( sdlRenderer );

}

void Renderer::addCharacterSpriteRenderer(Character & subject) {
    rendererRegistry.emplace(subject.getUUID(), spriteRendererFactory.createCharacterRenderer(subject));
}

void Renderer::addTileSpriteRenderer(const Tile & subject) {
    rendererRegistry.emplace(subject.getUUID(), spriteRendererFactory.createTileRenderer(subject));
}


