//
// Created by SJ Holland on 4/3/16.
//

#ifndef SDTTEST_DOT_H
#define SDTTEST_DOT_H

#include <SDL.h>
#include <vector>
#include "Tile.h"
#include "Level.h"
#include "../View/LTexture.h"

//The dot that will move around on the screen
class Dot
{
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;

    //Maximum axis velocity of the dot
    static const int DOT_VEL = 10;

    //Initializes the variables
    Dot();

    //Takes key presses and adjusts the dot's velocity
    void handleEvent( SDL_Event& e );

    //Moves the dot and check collision against tiles
    void move( std::vector<Tile> & tiles, Level* level);

    //Centers the camera over the dot
    void setCamera( SDL_Rect& camera, Level* level, int screen_width, int screen_height );

    SDL_Rect getCollisionBox();

private:
    //Collision box of the dot
    SDL_Rect mBox;

    //The velocity of the dot
    int mVelX, mVelY;

    bool touchesWall( std::vector<Tile> & tiles );
};


#endif //SDTTEST_DOT_H

// TODO: make everything as const as possible