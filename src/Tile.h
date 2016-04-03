//
// Created by SJ Holland on 4/3/16.
//

#ifndef SDTTEST_TILE_H
#define SDTTEST_TILE_H

#include <SDL.h>
#include "LTexture.h"

const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;

class Tile
{
public:
    //Initializes position and type
    Tile( int x, int y, int tileType );

    //Shows the tile
    void render( SDL_Rect& camera, SDL_Renderer* gRenderer, LTexture & texture );

    //Get the tile type
    int getType();

    //Get the collision box
    SDL_Rect getBox();

private:
    //The attributes of the tile
    SDL_Rect mBox;

    //The tile type
    int mType;
};


#endif //SDTTEST_TILE_H
