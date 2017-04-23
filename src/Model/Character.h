/*
 Created by SJ Holland on 4/3/16.

 Represents an entity (player or NPC) that is capable of moving around the game world.
*/

#ifndef SPACEGAME_CHARACTER_H
#define SPACEGAME_CHARACTER_H

#include <SDL.h>
#include <vector>
#include "Tile.h"
#include "GameObject.h"

enum Direction { left, right, up, down };

class Character: public GameObject
{
public:
    //Maximum axis velocity
    static const int CHARACTER_VEL = 10;

    //Initializes the variables
    Character(int w, int h, int startingX, int startingY, std::string n);

    int getXVelocity() const { return mVelX; };

    int getYVelocity() const { return mVelY; };

    Direction getFacingDirection() const { return direction; };

    void setThrust( Direction d, bool isActive );

    ~Character() {}

private:

    //The velocity of the character
    int mVelX, mVelY;

    Direction direction;

};

#endif //SPACEGAME_CHARACTER_H
