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
    GameObject shouldCollide("shouldCollide");
    GameObject shouldntCollide("shouldntCollide");
    SDL_Rect shouldCollideBox ;
    SDL_Rect shouldntCollideBox;
    shouldCollideBox.x = 0;
    shouldCollideBox.y = 0;
    shouldCollideBox.w = 1;
    shouldCollideBox.h = 1;
    shouldntCollideBox.x = 160;
    shouldntCollideBox.y = 160;
    shouldntCollideBox.w = 1;
    shouldntCollideBox.h = 1;
    shouldCollide.setCollisionBox(shouldCollideBox);
    shouldntCollide.setCollisionBox(shouldntCollideBox);
    EXPECT_TRUE(tile1.collidesWith(shouldCollide));
    EXPECT_FALSE(tile1.collidesWith(shouldntCollide));
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