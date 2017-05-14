//
// Created by SJ Holland on 4/3/16.
//

#include "Character.h"

#include "Level.h"

Character::Character(int w, int h, int startingX, int startingY, std::string n)
        : mVelX(0), mVelY(0), direction(right), GameObject(n)
{
    //Initialize the collision box
    mBox.x = startingX;
    mBox.y = startingY;
    mBox.w = w;
    mBox.h = h;
    tangible = true;
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

    if (mVelX > 0)
    {
        direction = right;
    }
    else if (mVelX < 0)
    {
        direction = left;
    }
}

void Character::onCollide(GameObject & o) {
    GameObject::onCollide(o);
}

void Character::updateState() {
    GameObject::updateState();
}



