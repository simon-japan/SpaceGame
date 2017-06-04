//
// Created by SJ Holland on 2017/05/17.
//

#include "HealthProperties.h"


void HealthProperties::takeHit(int attackPower)
{
    if (destructible)
    {
        health -= attackPower;
    }
}
