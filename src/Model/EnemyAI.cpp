//
// Created by SJ Holland on 9/4/16.
//

#include "EnemyAI.h"

// TODO: ensure that bodies don't teleport through walls
// (doesn't happen right now, but would be good to have some kind of guarantee)

void EnemyAI::updateState(Character & body) {
    auto xVel = body.getXVelocity();
    auto yVel = body.getYVelocity();

    if (xVel == 0 && yVel == 0)
    {
        int newDirection = rand() % 4;
        switch (newDirection)
        {
            case 1:
            {
                body.setThrust(Direction::up, true);
                break;
            }
            case 2:
            {
                body.setThrust(Direction::down, true);
                break;
            }
            case 3:
            {
                body.setThrust(Direction::left, true);
                break;
            }
            case 4:
            {
                body.setThrust(Direction::right, true);
                break;
            }
            default:
            {
                break;
            }
        }
    }
    else if(body.isBlocked())
    {
        if (xVel > 0)
        {
            body.setThrust(right, false);
            body.setThrust(Direction::down, true);
        }
        else if (xVel < 0)
        {
            body.setThrust(left, false);
            body.setThrust(Direction::up, true);
        }
        else if (yVel > 0)
        {
            body.setThrust(down, false);
            body.setThrust(Direction::left, true);
        }
        else if (yVel < 0)
        {
            body.setThrust(up, false);
            body.setThrust(Direction::right, true);
        }
    }
}
