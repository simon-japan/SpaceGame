//
// Created by SJ Holland on 4/3/16.
//

#ifndef SDTTEST_LEVEL_H
#define SDTTEST_LEVEL_H


#include <vector>
#include "Tile.h"

class Level {

public:
    Level(): max_x(0), min_x(0), max_y(0), min_y(0) {};
    void addTile(int x, int y, const TileType & tileType);
    int getHeight();
    int getWidth();
    const std::vector<Tile> & getTiles() const { return tiles; }

private:
    int max_x;
    int min_x;
    int max_y;
    int min_y;
    std::vector<Tile> tiles;
};


#endif //SDTTEST_LEVEL_H
