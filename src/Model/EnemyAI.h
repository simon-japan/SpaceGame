//
// Created by SJ Holland on 9/4/16.
//

#ifndef SPACEGAME_ENEMYAI_H
#define SPACEGAME_ENEMYAI_H

#include "Property.h"
#include "AI.h"

class GameObject;

class EnemyAI : public AI{
public:
    EnemyAI(GameObject & go) : AI(go) {};
    void updateState() override;
};


#endif //SPACEGAME_ENEMYAI_H
