//
// Created by SJ Holland on 4/3/16.
//

#ifndef SDTTEST_LEVEL_H
#define SDTTEST_LEVEL_H


#include <vector>
#include "Tile.h"

class Level {

public:

    Level(int w, int h, std::vector<Tile> & t): width(w), height(h), tiles(t) {};

    int getHeight();
    int getWidth();
    std::vector<Tile> & getTiles();


private:
    int height;
    int width;
    std::vector<Tile> & tiles;
};


#endif //SDTTEST_LEVEL_H
