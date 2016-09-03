//
// Created by SJ Holland on 4/3/16.
//

#ifndef SPACEGAME_TILE_H
#define SPACEGAME_TILE_H

#include <SDL.h>
#include "TileType.h"
#include "GameObject.h"
#include <iostream>

const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;

class Tile: public GameObject
{
public:
    //Initializes position and type
    Tile( int x, int y, const TileType & type);

    std::string getName() const override { return tileType.getName(); }

    bool isTangible() const override { return tileType.isTangible(); }

    // TODO: add MOVE SEMANTICS!!

private:

    const TileType & tileType;

    friend std::ostream& operator<<(std::ostream &, const Tile&);
};

inline std::ostream& operator<<(std::ostream &os, const Tile& t)
{
    return os << "Tile(x:" << t.mBox.x << ", y:" << t.mBox.y << ", type:" << t.tileType.getName() << ")";
}

#endif //SPACEGAME_TILE_H
