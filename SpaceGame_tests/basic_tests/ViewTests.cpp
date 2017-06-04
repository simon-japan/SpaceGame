//
// Created by SJ Holland on 2017/06/03.
//

#include <gtest/gtest.h>
#include "../../src/View/GameObjectRendererFactory.h"
#include "../../src/View/TextureRepository.h"
#include "../../src/Serialization/SpriteLoader.h"

using namespace std;

class ViewTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,
                                    600, SDL_WINDOW_SHOWN );
        gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
        SpriteLoader spriteLoader(textureRepository, spriteRepository, gRenderer);
        int rc = spriteLoader.loadSprites("../../configuration/sprites.xml");
        gameObjectRendererFactory = new GameObjectRendererFactory(spriteRepository);
    }

    virtual void TearDown() {
        SDL_DestroyRenderer( gRenderer );
        SDL_DestroyWindow( gWindow );
        gWindow = NULL;
        gRenderer = NULL;
        gameObjectRendererFactory = nullptr;
    }

    SDL_Window* gWindow = nullptr;
    SpriteRepository spriteRepository;
    TextureRepository textureRepository;
    SDL_Renderer* gRenderer = nullptr;
    GameObjectRendererFactory * gameObjectRendererFactory = nullptr;
};

TEST_F(ViewTest, SpriteRendererCreation)
{
    GameObject gameObject("TestGameObject");
    gameObject.getVisualProperties().setDefaultSpriteName("Player");
    std::unique_ptr<GameObjectRenderer> renderer = gameObjectRendererFactory->createGameObjectRenderer(gameObject);
}

# todo: WIP