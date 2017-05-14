//
// Created by SJ Holland on 4/9/16.
//

#include <gtest/gtest.h>
#include "../../src/Model/Tile.h"
#include "../../src/Model/Level.h"

TEST(TileTests, TileCreation) {
    TileType tt("SimonTile", true);
    Tile tile (1,2, tt);
    EXPECT_EQ(0, strcmp("SimonTile", tile.getName().c_str()));
}

TEST(TileTests, CollisionDoesWork) {
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

TEST(TileTests, PrintsCorrectly)
{
    TileType tt("SimonTile", true);
    Tile tile1(80,160, tt);
    std::ostringstream os;
    os << tile1;
    EXPECT_STREQ(os.str().c_str(), "Tile(x:80, y:160, type:SimonTile)");
}

TEST(LevelTests, DimensionsUpdateCorrectly)
{
    Level level;
    TileType whateverType("eh", false);
    level.addTile(0,0, whateverType);
    level.addTile(0,80, whateverType);
    level.addTile(-80,0, whateverType);
    EXPECT_EQ(level.getHeight(),160);
    EXPECT_EQ(level.getWidth(), 160);
}

TEST(GameObjectTests, GameObjectsCanMove)
{
    Level level(100, 100);
    auto objectPtr(std::make_shared<GameObject>("myObject", 0, 0, 1, 1));
    objectPtr->getPhysical().setThrust(right, true);
    level.addCharacter(std::shared_ptr<GameObject>(objectPtr));
    level.updateObjects();
    EXPECT_NE(objectPtr->getCollisionBox().x, 0);
}