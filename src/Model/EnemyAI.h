//
// Created by SJ Holland on 9/4/16.
//

#ifndef SPACEGAME_ENEMYAI_H
#define SPACEGAME_ENEMYAI_H

#include "Property.h"

class GameObject;

class EnemyAI : public Property{
public:
    EnemyAI(GameObject & go) : Property(go) {}
    void updateState();
};


#endif //SPACEGAME_ENEMYAI_H
