//
// Created by SJ Holland on 2017/06/03.
//

#ifndef SPACEGAME_AI_H
#define SPACEGAME_AI_H

#include "Property.h"

class GameObject;

class AI : public Property{
public:
    AI(GameObject & go) : Property(go) {}

    virtual void updateState() override {};
};

#endif //SPACEGAME_AI_H
