//
// Created by SJ Holland on 4/3/16.
//

#include "Character.h"

Character::Character(int w, int h, std::string n): width(w), height(h), name(n)
{
    //Initialize the collision box
    mBox.x = 0;
    mBox.y = 0;
    mBox.w = width;
    mBox.h = height;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Character::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= CHARACTER_VEL; break;
            case SDLK_DOWN: mVelY += CHARACTER_VEL; break;
            case SDLK_LEFT: mVelX -= CHARACTER_VEL; break;
            case SDLK_RIGHT: mVelX += CHARACTER_VEL; break;
            default:break;
        }
    }
        //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += CHARACTER_VEL; break;
            case SDLK_DOWN: mVelY -= CHARACTER_VEL; break;
            case SDLK_LEFT: mVelX += CHARACTER_VEL; break;
            case SDLK_RIGHT: mVelX -= CHARACTER_VEL; break;
            default:break;
        }
    }
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

// TODO: move control to Controller module
void Character::move(Level & level)
{
    const std::vector<Tile> & tiles(level.getTiles());

    //Move the dot left or right
    mBox.x += mVelX;

    //If the dot went too far to the left or right or touched a wall
    if( ( mBox.x < 0 ) || ( mBox.x + width > level.getWidth() ) || touchesWall( tiles ) )
    {
        //move back
        mBox.x -= mVelX;
    }

    //Move the dot up or down
    mBox.y += mVelY;

    //If the dot went too far up or down or touched a wall
    if( ( mBox.y < 0 ) || ( mBox.y + height > level.getHeight() ) || touchesWall( tiles ) )
    {
        //move back
        mBox.y -= mVelY;
    }
}

void Character::setCamera(SDL_Rect & camera, Level & level, int screen_width, int screen_height)
{
    //Center the camera over the dot
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

SDL_Rect Character::getCollisionBox() {
    return mBox;
}
