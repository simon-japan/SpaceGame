//
// Created by SJ Holland on 2017/03/20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../src/Model/QuadTree.h"

using namespace std;

class QuadTreeTest : public ::testing::Test
{
protected:
    QuadTreeTest(): rootTree(0, SDL_Rect{0,0,100,100}) {};

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    shared_ptr<GameObject> createGameObject(int x, int y, int w, int h)
    {
        shared_ptr<GameObject> ptr(new GameObject("test object"));
        ptr->setCollisionBox({x,y,w,h});
        return ptr;
    }

    QuadTree rootTree;
};

TEST_F(QuadTreeTest, QuadTreeCreation)
{
    QuadTree quadTree(0, SDL_Rect{0,0,100,100});
}

TEST_F(QuadTreeTest, InsertOneGameObject)
{
    rootTree.insert(createGameObject(5,5,5,5));
    EXPECT_EQ(rootTree.objectsCount(false), 1);
}

TEST_F(QuadTreeTest, Clear)
{
    rootTree.insert(createGameObject(5,5,5,5));
    rootTree.clear();
    EXPECT_EQ(rootTree.objectsCount(false), 0);
}

TEST_F(QuadTreeTest, Split)
{
    vector<int> xs = {0, 1, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    vector<int> ys = {0};
    vector<shared_ptr<GameObject>> gameObjects;

    for (int x : xs)
    {
        for (int y : ys)
        {
            gameObjects.push_back(createGameObject(x, y, 5, 5));
        }
    }

    for (auto obj : gameObjects)
    {
        rootTree.insert(obj);
    }

    array<unique_ptr<QuadTree>, 4> & rootNodes = rootTree.getNodes();

    cout << endl << endl << "Printing out quadtree: " << endl << rootTree << endl << flush;

    EXPECT_EQ(rootTree.objectsCount(true), xs.size() * ys.size());
}