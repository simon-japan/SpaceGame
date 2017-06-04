//
// Created by SJ Holland on 4/5/16.
//

#include <algorithm>
#include "Renderer.h"

using namespace std;

void Renderer::renderLevel(SDL_Rect & camera, Level & level) {

    //Clear screen
    SDL_SetRenderDrawColor( sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( sdlRenderer );

    GameObjectRenderer * gameObjectRenderer = nullptr;

    //Render tiles from level
    std::vector<std::shared_ptr<GameObject> > & gameObjects = level.getGameObjects();
    std::sort(gameObjects.begin(), gameObjects.end(), compareZDepth);
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

bool Renderer::compareZDepth(const std::shared_ptr<GameObject> & go1, const std::shared_ptr<GameObject> & go2)
{
    return go1->getVisualProperties().getZ() < go2->getVisualProperties().getZ();
}
