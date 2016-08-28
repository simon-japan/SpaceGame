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
    Character(int w, int h, int startingX, int startingY, std::string n);

    //Takes key presses and adjusts the character's velocity
    void handleEvent( SDL_Event& e );

    //Moves the character and check collision against tiles
    void move(Level & level);

    //Centers the camera over the character
    void setCamera(SDL_Rect & camera, Level & level, int screen_width, int screen_height);

    SDL_Rect getCollisionBox() const { return mBox; };

    int getXVelocity() const { return mVelX; };

    int getYVelocity() const { return mVelY; };

    Direction getDirection() const { return direction; };

private:
    //Collision box of the character
    SDL_Rect mBox;

    //The velocity of the character
    int mVelX, mVelY;

    int width, height;

    Direction direction;

    std::string name;

    bool touchesWall( const std::vector<Tile> & tiles );

};


#endif //SDTTEST_DOT_H

// TODO: make everything as const as possible