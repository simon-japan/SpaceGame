//
// Created by SJ Holland on 4/24/16.
//

#include <gtest/gtest.h>
#include "../../src/Serialization/SpriteLoader.h"

class SpriteLoaderTest : public ::testing::Test {
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

TEST_F(SpriteLoaderTest, CanLoadValidFile)
{
    SpriteLoader spriteLoader;
    int rc = spriteLoader.loadSprites("sprites.xml", spriteRepository, textureRepository, gRenderer);
    EXPECT_EQ(rc, 0);

}

TEST_F(SpriteLoaderTest, ComplainIfFileDoesntExist)
{
    SpriteLoader spriteLoader;
    int rc = spriteLoader.loadSprites("bogus.xml", spriteRepository, textureRepository, gRenderer);
    EXPECT_NE(rc, 0);
}
