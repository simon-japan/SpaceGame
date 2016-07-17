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

/*std::vector<std::reference_wrapper<Tile>> & Level::getTiles() {
    std::vector<std::reference_wrapper<Tile>> tile_refs;
    for (auto & tile : tiles)
    {
        tile_refs.push_back(std::reference_wrapper<Tile>(*tile));
    }
    return tile_refs;
}*/



void Level::addTile(int x, int y, const TileType & tileType) {
    tiles.emplace_back(x, y, tileType);
    if (x > max_x)
    {
        max_x = x;
    }
    if (x < min_x)
    {
        min_x = x;
    }
    if (x > max_y)
    {
        max_y = y;
    }
    if (x < min_y)
    {
        min_y = y;
    }
}








