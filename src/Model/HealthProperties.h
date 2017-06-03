//
// Created by SJ Holland on 2017/05/17.
//

#ifndef SPACEGAME_HEALTHPROPERTIES_H
#define SPACEGAME_HEALTHPROPERTIES_H


#include "Property.h"

class HealthProperties : public Property
{
public:
    HealthProperties(GameObject & go) : Property(go)
    {}

    int getHealth() const { return health; }

    int getAttackPower() { return attackPower; }

    void takeHit(int attackPower);

protected:
    int health;
    int attackPower;
    bool destructible;
};


#endif //SPACEGAME_HEALTHPROPERTIES_H
