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
    tiles.emplace_back(x, y, tileType);
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
    characters.insert(pair<string, shared_ptr<Character>>(character->getName(), character));
}

void Level::moveCharacters() {
    for (auto it = beginCharacters(); it != endCharacters(); it++)
    {
        auto c = it->second;
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
}

void Level::tryMoveGameObject(GameObject & o, int amount, Axis axis) {
    // Copy of the object's collision box
    SDL_Rect collisionBox = o.getCollisionBox();

    if (axis == Xaxis)
    {
        collisionBox.x += amount;

        //If the character went too far to the left or right or touched a wall
        if(wouldCollide(collisionBox, Xaxis, o))
        {
            //move back
            collisionBox.x -= amount;
            o.setBlocked(true);
        }
    }
    else
    {
        collisionBox.y += amount;

        //If the character went too far to the left or right or touched a wall
        if(wouldCollide(collisionBox, Yaxis, o))
        {
            //move back
            collisionBox.y -= amount;
            o.setBlocked(true);
        }
    }
    o.setCollisionBox(collisionBox);
}

bool Level::wouldCollide(SDL_Rect target, Axis axis, GameObject & o) {

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

    // Super-naive collision detection: BAD
    // Todo: use BSP etc
    for (auto & tile : tiles)
    {
        if (tile.isTangible() && Geometry::checkCollision(target, tile.getCollisionBox()))
        {
            return true;
        }
    }
    for (auto it = beginCharacters(); it != endCharacters(); it++)
    {
        if (o.getUUID() != it->second->getUUID() && Geometry::checkCollision(target, it->second->getCollisionBox()))
        {
            return true;
        }
    }

    return false;
}

void Level::updateAI() {
    for (auto it = beginCharacters(); it != endCharacters(); it++) {
        auto c = it->second;
        if (c->getName().compare("Player")) // Update the AI state if it's a NPC
        {
            EnemyAI::updateState(*c);
        }
    }
}







