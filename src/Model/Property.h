//
// Created by SJ Holland on 2017/05/14.
//

#ifndef SPACEGAME_PROPERTY_H
#define SPACEGAME_PROPERTY_H

class GameObject;

class Property {
public:
    Property(GameObject & go): gameObject(go){};
    virtual ~Property(){};
    virtual void updateState() {};

protected:
    GameObject & gameObject;
};

#endif //SPACEGAME_PROPERTY_H
