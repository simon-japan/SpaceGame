//
// Created by SJ Holland on 4/3/16.
//

#ifndef SDTTEST_TILE_H
#define SDTTEST_TILE_H

#include <SDL.h>
#include <string>

const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;

class Tile
{
public:
    //Initializes position and type
    Tile( int x, int y, std::string tileType, bool tangible);

    //Get the tile type
    std::string getType();

    //Get the collision box
    SDL_Rect getCollisionBox();

    bool collidesWith( const SDL_Rect & rect ) const;

private:
    //The attributes of the tile
    SDL_Rect mBox;

    //The tile type
    std::string mType;

    bool isTangible;
};


#endif //SDTTEST_TILE_H
