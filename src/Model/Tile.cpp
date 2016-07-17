//
// Created by SJ Holland on 4/3/16.
//

#include "Tile.h"
#include "Geometry.h"

Tile::Tile( int x, int y, const TileType & t): tileType (t)
{
    mBox.w = TILE_WIDTH;
    mBox.h = TILE_HEIGHT;
    mBox.x = x * TILE_WIDTH;
    mBox.y = y * TILE_HEIGHT;
}

const std::string Tile::getTypeName() const
{
    return tileType.getName();
}

const SDL_Rect Tile::getCollisionBox() const
{
    return mBox;
}

bool Tile::collidesWith(const SDL_Rect & rect) const {
    return tileType.isTangible() && Geometry::checkCollision(rect, mBox);
}
