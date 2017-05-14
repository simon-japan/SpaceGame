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

    GameObjectRenderer * gameObjectRenderer = nullptr;

    //Render tiles from level
    const std::vector<std::shared_ptr<Tile> > & tiles = level.getTiles();
    for( const auto & tile : tiles )
    {
        if (rendererRegistry.find(tile->getUUID()) == rendererRegistry.end())
        {
            addTileSpriteRenderer(*tile);
        }
        gameObjectRenderer = &*rendererRegistry[tile->getUUID()];
        gameObjectRenderer->render(camera, sdlRenderer);

    }

    //Render characters - after all of the tiles, because the characters are on top.
    for (auto character : level.getCharacters()) {

        if (rendererRegistry.find(character->getUUID()) == rendererRegistry.end())
        {
            addCharacterSpriteRenderer(*character);
        }
        gameObjectRenderer = &*rendererRegistry[character->getUUID()];
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


