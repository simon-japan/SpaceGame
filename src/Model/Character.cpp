//
// Created by SJ Holland on 4/3/16.
//

#include "Character.h"

Character::Character(int w, int h, int startingX, int startingY, std::string n)
        : mVelX(0), mVelY(0), direction(right), GameObject(n)
{
    //Initialize the collision box
    mBox.x = startingX;
    mBox.y = startingY;
    mBox.w = w;
    mBox.h = h;

}

bool Character::touchesWall( const std::vector<Tile> & tiles )
{
    //Go through the tiles
    for( auto & tile : tiles )
    {
        if (tile.collidesWith(mBox))
        {
            return true;
        }
    }

    //If no wall tiles were touched
    return false;
}

void Character::move(Level & level)
{
    const std::vector<Tile> & tiles(level.getTiles());

    //Move the character left or right
    mBox.x += mVelX;

    if (mVelX > 0)
    {
        direction = right;
    }
    else if (mVelX < 0)
    {
        direction = left;
    }

    //If the character went too far to the left or right or touched a wall
    if( ( mBox.x < 0 ) || ( mBox.x + mBox.w > level.getWidth() ) || touchesWall( tiles ) )
    {
        //move back
        mBox.x -= mVelX;
    }

    //Move the character up or down
    mBox.y += mVelY;

    //If the character went too far up or down or touched a wall
    if( ( mBox.y < 0 ) || ( mBox.y + mBox.h > level.getHeight() ) || touchesWall( tiles ) )
    {
        //move back
        mBox.y -= mVelY;
    }
}

void Character::setThrust(Direction d, bool isActive) {
    //Adjust the velocity
    if (isActive) {
        switch (d) {
            case up:
                mVelY -= CHARACTER_VEL;
                break;
            case down:
                mVelY += CHARACTER_VEL;
                break;
            case left:
                mVelX -= CHARACTER_VEL;
                break;
            case right:
                mVelX += CHARACTER_VEL;
                break;
            default:
                break;
        }
    } else {
        switch (d) {
            case up:
                mVelY += CHARACTER_VEL;
                break;
            case down:
                mVelY -= CHARACTER_VEL;
                break;
            case left:
                mVelX += CHARACTER_VEL;
                break;
            case right:
                mVelX -= CHARACTER_VEL;
                break;
            default:
                break;
        }
    }
}

