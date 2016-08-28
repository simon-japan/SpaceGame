//
// Created by SJ Holland on 4/3/16.
//

#include "Character.h"

Character::Character(int w, int h, int startingX, int startingY, std::string n)
        : width(w), height(h), mVelX(0), mVelY(0), direction(right), GameObject(n)
{
    //Initialize the collision box
    mBox.x = startingX;
    mBox.y = startingY;
    mBox.w = width;
    mBox.h = height;

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
    if( ( mBox.x < 0 ) || ( mBox.x + width > level.getWidth() ) || touchesWall( tiles ) )
    {
        //move back
        mBox.x -= mVelX;
    }

    //Move the character up or down
    mBox.y += mVelY;

    //If the character went too far up or down or touched a wall
    if( ( mBox.y < 0 ) || ( mBox.y + height > level.getHeight() ) || touchesWall( tiles ) )
    {
        //move back
        mBox.y -= mVelY;
    }
}

void Character::setCamera(SDL_Rect & camera, Level & level, int screen_width, int screen_height)
{
    //Center the camera over the character
    camera.x = ( mBox.x + width / 2 ) - screen_width / 2;
    camera.y = ( mBox.y + height / 2 ) - screen_height / 2;

    int level_width = level.getWidth();
    int level_height = level.getHeight();

    //Keep the camera in bounds
    if( camera.x < 0 )
    {
        camera.x = 0;
    }
    if( camera.y < 0 )
    {
        camera.y = 0;
    }
    if( camera.x > level_width - camera.w )
    {
        camera.x = level_width - camera.w;
    }
    if( camera.y > level_height - camera.h )
    {
        camera.y = level_height - camera.h;
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

