//
// Created by SJ Holland on 4/3/16.
//

#include "Level.h"
#include "Geometry.h"
#include "EnemyAI.h"

using namespace std;

int Level::getHeight() {
    return max_y - min_y;
}

int Level::getWidth() {
    return max_x - min_x;
}

void Level::addTile(int x, int y, const TileType & tileType) {
    tiles.emplace_back(new Tile(x, y, tileType));
    if (x > max_x)
    {
        max_x = x + TILE_WIDTH;
    }
    if (x < min_x)
    {
        min_x = x - TILE_WIDTH;
    }
    if (y > max_y)
    {
        max_y = y + TILE_HEIGHT;
    }
    if (y < min_y)
    {
        min_y = y + TILE_HEIGHT;
    }
}

void Level::addCharacter(std::shared_ptr<Character> character) {
    characters.push_back(character);
}

/*void Level::moveCharacters() {
    refreshQuadTree();

    for (auto c : characters)
    {
        auto xVelocity = c->getXVelocity();
        auto yVelocity = c->getYVelocity();

        if (xVelocity == 0 && yVelocity == 0)
        {
            continue;
        }

        c->setBlocked(false);

        tryMoveGameObject(*c, xVelocity, Xaxis);
        tryMoveGameObject(*c, yVelocity, Yaxis);
    }
}*/

void Level::tryMoveGameObject(GameObject & o, int xAmount, int yAmount) {
    // Copy of the object's collision box
    SDL_Rect collisionBox = o.getCollisionBox();


    collisionBox.x += xAmount;

    //If the character went too far to the left or right or touched a wall
    if(wouldExitLevel(collisionBox, Xaxis))
    {
        collisionBox.x -= xAmount;
        o.onLevelExit();
    }
    checkCollisions(collisionBox, o);
//        if(checkCollisions(collisionBox, o))
//        {
//            //move back
//            collisionBox.x -= xAmount;
//            o.setBlocked(true);
//        }

        collisionBox.y += yAmount;

    //If the character went too far to the left or right or touched a wall
    if(wouldExitLevel(collisionBox, Yaxis))
    {
        //move back
        collisionBox.y -= yAmount;
        o.onLevelExit();
    }
    checkCollisions(collisionBox, o);
//        if(checkCollisions(collisionBox, o))
//        {
//            //move back
//            collisionBox.y -= yAmount;
//            o.setBlocked(true);
//        }
    o.setCollisionBox(collisionBox);
}

bool Level::wouldExitLevel(SDL_Rect target, Axis axis) {
    if (axis == Xaxis)
    {
        if (target.x < min_x  || target.x + target.w > max_x)
        {
            return true;
        }
    }
    else
    {
        if (target.y < min_y  || target.y + target.h > max_y)
        {
            return true;
        }
    }
    return false;
}

void Level::checkCollisions(SDL_Rect target, GameObject & o) {
    vector<shared_ptr<GameObject>> tilesWithinReach;
    collisionQuadTree.retrieve(tilesWithinReach, o);

    for (auto & tile : tilesWithinReach)
    {
        if (tile->isTangible() && Geometry::checkCollision(target, tile->getCollisionBox()))
        {
            o.onCollide(*tile);
        }
    }

    // Currently, not using BSP for collision detection between characters (because they may move around the map)
    for (auto character : characters)
    {
        if (o.getUUID() != character->getUUID() && Geometry::checkCollision(target, character->getCollisionBox()))
        {
            o.onCollide(*character);
        }
    }

}

void Level::updateAI() {
    for (auto character : characters) {
        if (character->getName().compare("Player"))
        {
            EnemyAI::updateState(*character);
        }
    }
}

void Level::refreshQuadTree() {
    // Clear all objects from the quad tree, and set its bounds to be the same as the shape of the level
    SDL_Rect levelBounds;
    levelBounds.x = min_x;
    levelBounds.y = min_y;
    levelBounds.w = getWidth();
    levelBounds.h = getHeight();
    collisionQuadTree.clear( levelBounds );

    for (auto object : tiles)
    {
        collisionQuadTree.insert(object);
    }
}







