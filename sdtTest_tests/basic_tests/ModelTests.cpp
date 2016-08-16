//
// Created by SJ Holland on 4/9/16.
//

#include <gtest/gtest.h>
#include "../../src/Model/Tile.h"

TEST(TileTest, TileCreation) {
    TileType tt("SimonTile", true);
    Tile tile (1,2, tt);
    EXPECT_EQ(0, strcmp("SimonTile", tile.getTypeName().c_str()));
}

TEST(TileTest, CollisionDoesWork) {
    TileType tt("SimonTile", true);
    Tile tile1(0,0, tt);
    SDL_Rect should_collide;
    SDL_Rect shouldnt_collide;
    should_collide.x = 0;
    should_collide.y = 0;
    should_collide.w = 1;
    should_collide.h = 1;
    shouldnt_collide.x = 160;
    shouldnt_collide.y = 160;
    shouldnt_collide.w = 1;
    shouldnt_collide.h = 1;
    EXPECT_TRUE(tile1.collidesWith(should_collide));
    EXPECT_FALSE(tile1.collidesWith(shouldnt_collide));
}