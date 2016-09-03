//
// Created by SJ Holland on 4/3/16.
//

#ifndef SPACEGAME_CHARACTER_H
#define SPACEGAME_CHARACTER_H

#include <SDL.h>
#include <vector>
#include "Tile.h"
#include "Level.h"
#include "GameObject.h"

enum Direction { left, right, up, down };

class Level;

// Todo: proper comments to explain what this class does
class Character: public GameObject
{
public:
    //Maximum axis velocity
    static const int CHARACTER_VEL = 10;

    //Initializes the variables
    Character(int w, int h, int startingX, int startingY, std::string n);

    int getXVelocity() const { return mVelX; };

    int getYVelocity() const { return mVelY; };

    Direction getDirection() const { return direction; };

    void setThrust( Direction d, bool isActive );

private:

    //The velocity of the character
    int mVelX, mVelY;

    Direction direction;

};

#endif //SPACEGAME_CHARACTER_H
