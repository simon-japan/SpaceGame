//
// Created by SJ Holland on 4/3/16.
//

#include "Level.h"
#include "Geometry.h"

using namespace std;

int Level::getHeight()
{
    return max_y - min_y;
}

int Level::getWidth()
{
    return max_x - min_x;
}

void Level::addGameObject(std::shared_ptr<GameObject> gameObjectPtr){
    gameObjects.push_back(gameObjectPtr);
    SDL_Rect bounds = gameObjectPtr->getCollisionBox();
    if (bounds.x > max_x) {
        max_x = bounds.x + bounds.w;
    }
    if (bounds.x < min_x) {
        min_x = bounds.x - bounds.w;
    }
    if (bounds.y > max_y) {
        max_y = bounds.y + bounds.h;
    }
    if (bounds.y < min_y) {
        min_y = bounds.y + bounds.h;
    }
}

void Level::tryMoveGameObject(GameObject & o, int xAmount, int yAmount)
{
    // Copy of the object's collision box
    SDL_Rect collisionBox = o.getCollisionBox();

    collisionBox.x += xAmount;

    //If the character went too far to the left or right or touched a wall
    if (wouldExitLevel(collisionBox, Xaxis)) {
        collisionBox.x -= xAmount;
        o.onLevelExit();
    }

    if (checkCollisions(o)) {
        //move back
        collisionBox.x -= xAmount;
        o.getPhysicalProperties().setBlocked(true);
    }

    collisionBox.y += yAmount;

    //If the character went too far to the left or right or touched a wall
    if (wouldExitLevel(collisionBox, Yaxis)) {
        //move back
        collisionBox.y -= yAmount;
        o.onLevelExit();
    }

    if (checkCollisions(o)) {
        //move back
        collisionBox.y -= yAmount;
        o.getPhysicalProperties().setBlocked(true);
    }

    o.setCollisionBox(collisionBox);
}

bool Level::wouldExitLevel(SDL_Rect target, Axis axis)
{
    if (axis == Xaxis) {
        if (target.x < min_x || target.x + target.w > max_x) {
            return true;
        }
    } else {
        if (target.y < min_y || target.y + target.h > max_y) {
            return true;
        }
    }
    return false;
}

bool Level::checkCollisions(GameObject & target)
{
    SDL_Rect target_box = target.getCollisionBox();
    vector<shared_ptr<GameObject>> objectsWithinReach;
    collisionQuadTree.retrieve(objectsWithinReach, target);
    bool collided = false;

    for (auto & otherObject : objectsWithinReach) {
        if (target.getUUID() != target.getUUID() &&
                otherObject->getPhysicalProperties().isTangible() &&
            Geometry::checkCollision(target_box, otherObject->getCollisionBox()))
        {
            target.onCollide(*otherObject);
            collided = true;
        }
    }

    return collided;
}

void Level::updateObjects()
{
    refreshQuadTree();

    for (vector<shared_ptr<GameObject>>::iterator it = gameObjects.begin(); it != gameObjects.end();) {
        shared_ptr<GameObject> gameObjectPtr = *it;
        gameObjectPtr->updateState();

        auto & physicalProperties = gameObjectPtr->getPhysicalProperties();
        int velX = physicalProperties.getXVelocity();
        int velY = physicalProperties.getYVelocity();

        if (velX != 0 || velY != 0)
        {
            physicalProperties.setBlocked(false);
            tryMoveGameObject(*gameObjectPtr, velX, velY);
        }

        if (gameObjectPtr->getHealthProperties().getHealth() <= 0)
        {
            gameObjects.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Level::refreshQuadTree()
{
    // Clear all objects from the quad tree, and set its bounds to be the same as the shape of the level
    SDL_Rect levelBounds;
    levelBounds.x = min_x;
    levelBounds.y = min_y;
    levelBounds.w = getWidth();
    levelBounds.h = getHeight();
    collisionQuadTree.clear(levelBounds);

    for (auto object : gameObjects) {
        collisionQuadTree.insert(object);
    }
}







