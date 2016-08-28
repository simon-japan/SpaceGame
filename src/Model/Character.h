//
// Created by SJ Holland on 4/3/16.
//

#ifndef SDTTEST_DOT_H
#define SDTTEST_DOT_H

#include <SDL.h>
#include <vector>
#include "Tile.h"
#include "Level.h"
#include "GameObject.h"

enum Direction { left, right };

//The dot that will move around on the screen
class Character: public GameObject
{
public:
    //Maximum axis velocity
    static const int CHARACTER_VEL = 10;

    //Initializes the variables
    Character(int w, int h, std::string n);

    //Takes key presses and adjusts the character's velocity
    void handleEvent( SDL_Event& e );

    //Moves the character and check collision against tiles
    void move(Level & level);

    //Centers the camera over the dot
    void setCamera(SDL_Rect & camera, Level & level, int screen_width, int screen_height);

    SDL_Rect getCollisionBox();

    int getXVelocity() { return mVelX; };

    int getYVelocity() { return mVelY; };

    Direction getDirection() { return direction; };

private:
    //Collision box of the dot
    SDL_Rect mBox;

    //The velocity of the dot
    int mVelX, mVelY;

    int width, height;

    Direction direction;

    std::string name;

    bool touchesWall( const std::vector<Tile> & tiles );

};


#endif //SDTTEST_DOT_H

// TODO: make everything as const as possible