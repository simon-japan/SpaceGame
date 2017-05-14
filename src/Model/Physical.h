//
// Created by SJ Holland on 2017/05/13.
//

#ifndef SPACEGAME_PHYSICAL_H
#define SPACEGAME_PHYSICAL_H


#include "Property.h"

class Level;

enum Direction { left, right, up, down };

//Maximum axis velocity
static const int MAX_VEL = 10;

class Physical : public Property{
public:
    Physical(GameObject & go, int x, int y, Direction d) :
            Property(go),
            mVelX(x),
            mVelY(y),
            direction(left)
    {}

    virtual ~Physical(){};

    void updateState(Level & level);

    // Accessors

    int getXVelocity() const { return mVelX; };

    int getYVelocity() const { return mVelY; };

    Direction getFacingDirection() const { return direction; };

    bool isTangible() const { return tangible; }

    bool isBlocked() { return blocked; }

    // Mutators

    void setThrust( Direction d, bool isActive );

    void setTangible(bool t) { tangible = t; }

    void setBlocked(bool b) { blocked = b; }

    // Move somewhere else
    //virtual int getHealth() const = 0;
    //virtual void takeHit(int attackPower) = 0;
    //virtual void getAttackPower() = 0;

private:
    //The velocity of the character
    int mVelX, mVelY;

    Direction direction;

    bool tangible;

    bool movable;

    bool blocked;
};


#endif //SPACEGAME_PHYSICAL_H
