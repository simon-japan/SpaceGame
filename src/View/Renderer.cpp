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
    const std::vector<std::shared_ptr<GameObject> > & gameObjects = level.getGameObjects();
    for( const auto & gameObject : gameObjects )
    {
        auto uuid = gameObject->getUUID();
        if (rendererRegistry.find(uuid) == rendererRegistry.end())
        {
            rendererRegistry.emplace(uuid, gameObjectRendererFactory.createGameObjectRenderer(*gameObject));
        }
        gameObjectRenderer = &*rendererRegistry[uuid];
        gameObjectRenderer->render(camera, sdlRenderer);

    }

    //Update screen
    SDL_RenderPresent( sdlRenderer );

}

// Todo: implement a z-buffer or something so that the sprites can go on top of the tiles, etc.
