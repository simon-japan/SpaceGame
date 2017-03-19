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

    // Can collide with an object that overlaps
    SDL_Rect should_collide_box;
    should_collide_box.x = 0;
    should_collide_box.y = 0;
    should_collide_box.w = 1;
    should_collide_box.h = 1;
    GameObject should_collide_obj("ShouldCollide");
    should_collide_obj.setCollisionBox(should_collide_box);
    should_collide_obj.setTangible(true);
    EXPECT_TRUE(tile1.collidesWith(should_collide_obj));

    // Does not collide with an object that doesn't overlap
    SDL_Rect shouldnt_collide_box;
    shouldnt_collide_box.x = 160;
    shouldnt_collide_box.y = 160;
    shouldnt_collide_box.w = 1;
    shouldnt_collide_box.h = 1;
    GameObject shouldnt_collide_obj("ShouldCollide");
    should_collide_obj.setCollisionBox(shouldnt_collide_box);
    should_collide_obj.setTangible(true);
    EXPECT_FALSE(tile1.collidesWith(shouldnt_collide_obj));
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

TEST(QuadTreeTest, InsertsProperly)
{
    // Construct a quad tree for a 100*100 area
    QuadTree quadTree(0, SDL_Rect {0, 0, 100, 100});

    std::vector<std::shared_ptr<GameObject>> gameObjects;

    for (int i = 0; i < 100; i++)
    {
        SDL_Rect rect;
        rect.x = i;
        rect.y = i;
        rect.w = 1;
        rect.h = 1;
        std::shared_ptr<GameObject> gameObjectPtr (new GameObject(std::to_string(i)));
        gameObjectPtr->setCollisionBox(rect);
        gameObjectPtr->setTangible(true);
        gameObjects.push_back(gameObjectPtr);
        quadTree.insert(gameObjectPtr);
    }

    std::vector<std::shared_ptr<GameObject>> results;

    for (auto goPtr : gameObjects)
    {
        results.clear();
        quadTree.retrieve(results, *goPtr);
        EXPECT_EQ(results.size(), 7);
    }
}