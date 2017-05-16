//
// Created by SJ Holland on 2017/05/14.
//

#include "Physical.h"
#include "Level.h"

void Physical::updateState(Level & level) {
    if (mVelX != 0 || mVelY != 0)
    {
        blocked = false;
        level.tryMoveGameObject(gameObject, mVelX, mVelY);
    }
}

void Physical::setThrust(Direction d, bool isActive) {
    //Adjust the velocity
    if (isActive) {
        switch (d) {
            case up:
                mVelY -= MAX_VEL;
                break;
            case down:
                mVelY += MAX_VEL;
                break;
            case left:
                mVelX -= MAX_VEL;
                break;
            case right:
                mVelX += MAX_VEL;
                break;
            default:
                break;
        }
    } else {
        switch (d) {
            case up:
                mVelY += MAX_VEL;
                break;
            case down:
                mVelY -= MAX_VEL;
                break;
            case left:
                mVelX += MAX_VEL;
                break;
            case right:
                mVelX -= MAX_VEL;
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

