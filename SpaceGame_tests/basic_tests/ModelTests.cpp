//
// Created by SJ Holland on 4/9/16.
//

#include <gtest/gtest.h>
#include "../../src/Model/Tile.h"
#include "../../src/Model/Level.h"

using namespace std;

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
    level.addGameObject(make_shared<Tile>(0, 0, whateverType));
    level.addGameObject(make_shared<Tile>(0,80, whateverType));
    level.addGameObject(make_shared<Tile>(-80,0, whateverType));
    EXPECT_EQ(level.getHeight(),160);
    EXPECT_EQ(level.getWidth(), 160);
}

TEST(LevelTests, OnCollideIsTriggered)
{
    Level level(100, 100);
    auto object1Ptr(std::make_shared<GameObject>("myObject1", 0, 0, 1, 1));
    auto object2Ptr(std::make_shared<GameObject>("myObject2", 5, 0, 10, 10));
    object1Ptr->getPhysicalProperties().setTangible(true);
    object2Ptr->getPhysicalProperties().setTangible(true);
    object1Ptr->getPhysicalProperties().setThrust(Direction::right, true);
    level.addGameObject(std::shared_ptr<GameObject>(object1Ptr));
    level.addGameObject(std::shared_ptr<GameObject>(object2Ptr));
    level.updateObjects();

}

TEST(GameObjectTests, GameObjectsCanMove)
{
    Level level(100, 100);
    auto objectPtr(std::make_shared<GameObject>("myObject", 0, 0, 1, 1));
    objectPtr->getPhysicalProperties().setThrust(Direction::right, true);
    level.addGameObject(std::shared_ptr<GameObject>(objectPtr));
    level.updateObjects();
    EXPECT_NE(objectPtr->getCollisionBox().x, 0);
}

TEST(GameObjectTests, GameObjectsCanBeObstructed)
{
    Level level(100, 100);
    auto object1Ptr(std::make_shared<GameObject>("myObject1", 0, 0, 1, 1));
    auto object2Ptr(std::make_shared<GameObject>("myObject2", 5, 0, 10, 10));
    object1Ptr->getPhysicalProperties().setTangible(true);
    object2Ptr->getPhysicalProperties().setTangible(true);
    object1Ptr->getPhysicalProperties().setThrust(Direction::right, true);
    level.addGameObject(std::shared_ptr<GameObject>(object1Ptr));
    level.addGameObject(std::shared_ptr<GameObject>(object2Ptr));
    level.updateObjects();
    EXPECT_EQ(object1Ptr->getCollisionBox().x, 0);
}
