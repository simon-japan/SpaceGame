//
// Created by SJ Holland on 4/3/16.
//

#ifndef SPACEGAME_LEVEL_H
#define SPACEGAME_LEVEL_H


#include <vector>
#include <unordered_map>
#include "Tile.h"
#include "QuadTree.h"

class GameObject;

enum Axis {
    Xaxis, Yaxis
};

class Level {

public:
    Level(int w, int h) :
            max_x(w),
            min_x(0),
            max_y(h),
            min_y(0),
            collisionQuadTree(0, SDL_Rect{.x=0, .y=0, .w=w, .h=h}) {

    };

    Level() : Level(0, 0) {};

    void addGameObject(std::shared_ptr<GameObject> gameObjectPtr);

    int getHeight();

    int getWidth();

    const std::vector<std::shared_ptr<GameObject>> & getGameObjects() const { return gameObjects; };

    void tryMoveGameObject(GameObject & o, int xAmount, int yAmount);

    bool wouldExitLevel(SDL_Rect target, Axis axis);

    bool checkCollisions(GameObject & target);

    void updateObjects();

private:
    void refreshQuadTree();

    int max_x;
    int min_x;
    int max_y;
    int min_y;
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    QuadTree collisionQuadTree;
};


#endif //SPACEGAME_LEVEL_H
