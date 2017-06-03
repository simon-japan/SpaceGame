//
// Created by SJ Holland on 9/4/16.
//

#include "EnemyAI.h"
#include "PhysicalProperties.h"
#include "GameObject.h"

// TODO: different types of AI - not just decided by one big function


void EnemyAI::updateState() {
    PhysicalProperties & physical = gameObject.getPhysicalProperties();

    if (physical.getXVelocity() == 0 && physical.getYVelocity() == 0)
    {
        int newDirection = rand() % 4;
        switch (newDirection)
        {
            case 1:
            {
                physical.setThrust(Direction::up, true);
                break;
            }
            case 2:
            {
                physical.setThrust(Direction::down, true);
                break;
            }
            case 3:
            {
                physical.setThrust(Direction::left, true);
                break;
            }
            case 4:
            {
                physical.setThrust(Direction::right, true);
                break;
            }
            default:
            {
                break;
            }
        }
    }
    else if(gameObject.getPhysicalProperties().isBlocked())
    {
        if (gameObject.getName().compare("bullet") != 0) // It's not a bullet, so must be an enemy
        {
            int xVel = physical.getXVelocity();
            int yVel = physical.getYVelocity();
            if (xVel > 0) {
                physical.setThrust(right, false);
                physical.setThrust(Direction::down, true);
            } else if (xVel < 0) {
                physical.setThrust(left, false);
                physical.setThrust(Direction::up, true);
            } else if (yVel > 0) {
                physical.setThrust(down, false);
                physical.setThrust(Direction::left, true);
            } else if (yVel < 0) {
                physical.setThrust(up, false);
                physical.setThrust(Direction::right, true);
            }
        }
    }
}

