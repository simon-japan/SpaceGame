//
// Created by SJ Holland on 4/24/16.
//

#include <gtest/gtest.h>
#include "../../src/Serialization/SpriteLoader.h"
#include "../../src/Serialization/LevelLoader.h"

class SerializationTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,
                                        600, SDL_WINDOW_SHOWN );
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
        }

        virtual void TearDown() {
            SDL_DestroyRenderer( gRenderer );
            SDL_DestroyWindow( gWindow );
            gWindow = NULL;
            gRenderer = NULL;
        }

        SDL_Window* gWindow = nullptr;
        SpriteRepository spriteRepository;
        TextureRepository textureRepository;
        SDL_Renderer* gRenderer = nullptr;
};

TEST_F(SerializationTest, SpriteLoaderCanLoadValidSpriteFile)
{
    SpriteLoader spriteLoader(textureRepository, spriteRepository, gRenderer);
    int rc = spriteLoader.loadSprites("../../configuration/sprites.xml");
    EXPECT_EQ(rc, 0);

}

TEST_F(SerializationTest, SpriteLoaderComplainIfSpriteFileDoesntExist)
{
    SpriteLoader spriteLoader(textureRepository, spriteRepository, gRenderer);
    int rc = spriteLoader.loadSprites("bogus.xml");
    EXPECT_NE(rc, 0);
}

TEST_F(SerializationTest, LevelLoaderCanLoadValidFile)
{
    LevelLoader levelLoader;
    std::unique_ptr<Level> levelPtr(levelLoader.loadLevel("../../configuration/map.xml"));
    EXPECT_NE(levelPtr, nullptr);
}

TEST_F(SerializationTest, LevelLoaderReturnsNullForMissingFile)
{
    LevelLoader levelLoader;
    std::unique_ptr<Level> levelPtr(levelLoader.loadLevel("configuration/bogus.xml"));
    EXPECT_EQ(levelPtr, nullptr);
}

// Todo: test for file that exists but can't be processed correctly