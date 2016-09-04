//
// Created by SJ Holland on 4/9/16.
//

#include <gtest/gtest.h>
#include "../../src/Model/Tile.h"
#include "../../src/Model/Level.h"

TEST(TileTest, TileCreation) {
    TileType tt("SimonTile", true);
    Tile tile (1,2, tt);
    EXPECT_EQ(0, strcmp("SimonTile", tile.getName().c_str()));
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
    EXPECT_FALSE(tile1.collidesWith(<#initializer#>));
}

TEST(TileTest, PrintsCorrectly)
{
    TileType tt("SimonTile", true);
    Tile tile1(80,160, tt);
    std::ostringstream os;
    os << tile1;
    EXPECT_STREQ(os.str().c_str(), "Tile(x:80, y:160, type:SimonTile)");
}

TEST(LevelTest, DimensionsUpdateCorrectly)
{
    Level level;
    TileType whateverType("eh", false);
    level.addTile(0,0, whateverType);
    level.addTile(0,80, whateverType);
    level.addTile(-80,0, whateverType);
    EXPECT_EQ(level.getHeight(),160);
    EXPECT_EQ(level.getWidth(), 160);
}