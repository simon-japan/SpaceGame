//
// Created by SJ Holland on 4/3/16.
//

#include "Tile.h"
#include "Geometry.h"

Tile::Tile( int x, int y, int tileType )
{
    //Get the offsets
    mBox.x = x;
    mBox.y = y;

    //Set the collision box
    mBox.w = TILE_WIDTH;
    mBox.h = TILE_HEIGHT;

    //Get the tile type
    mType = tileType;
}

void Tile::render( SDL_Rect& camera, SDL_Renderer* gRenderer, LTexture & texture )
{
    //If the tile is on screen
    if(Geometry::checkCollision(  camera, mBox ) )
    {
        //Show the tile
        texture.render( mBox.x - camera.x, mBox.y - camera.y, gRenderer, &gTileClips[ mType ] );
    }
}

int Tile::getType()
{
    return mType;
}

SDL_Rect Tile::getBox()
{
    return mBox;
}