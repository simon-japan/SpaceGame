//
// Created by SJ Holland on 2017/05/14.
//

#ifndef SPACEGAME_PROPERTY_H
#define SPACEGAME_PROPERTY_H

#include "GameObject.h"

class Property {
public:
    Property(GameObject & go): gameObject(go){};
    virtual ~Physical(){};
    virtual void updateState() = 0;

protected:
    GameObject & gameObject;
};

#endif //SPACEGAME_PROPERTY_H
