//
// Created by SJ Holland on 4/3/16.
//

#include "Tile.h"
#include "Geometry.h"

Tile::Tile( int x, int y, std::string tileType, bool tangible): mType (tileType), isTangible(tangible)
{
    mBox.x = x;
    mBox.y = y;
    mBox.w = TILE_WIDTH;
    mBox.h = TILE_HEIGHT;
}

std::string Tile::getType()
{
    return mType;
}

SDL_Rect Tile::getCollisionBox()
{
    return mBox;
}

bool Tile::collidesWith(const SDL_Rect & rect) const {
    return isTangible && Geometry::checkCollision(rect, mBox);
}
