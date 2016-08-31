//
// Created by SJ Holland on 4/3/16.
//

#include "Level.h"

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










