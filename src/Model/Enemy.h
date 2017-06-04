//
// Created by SJ Holland on 2017/06/03.
//

#ifndef SPACEGAME_ENEMY_H
#define SPACEGAME_ENEMY_H


#include "GameObject.h"

class Enemy : public GameObject
{
public:

    Enemy(std::string name) : GameObject(name) {}

    Enemy(const std::string & n, int x, int y, int w, int h) : GameObject(n, x, y, w, h){}

protected:
    AI makeAI() override { return EnemyAI(*this); }

};


#endif //SPACEGAME_ENEMY_H
