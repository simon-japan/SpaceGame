//
// Created by SJ Holland on 2017/05/17.
//

#ifndef SPACEGAME_VISUALPROPERTIES_H
#define SPACEGAME_VISUALPROPERTIES_H


#include <string>
#include "Property.h"

class VisualProperties : public Property
{
public:
    VisualProperties(GameObject & go): Property(go), defaultSpriteName(""), z(0) {}

    VisualProperties(GameObject & go, std::string ds, int zValue): VisualProperties(go) {
        defaultSpriteName = ds;
        z = zValue;
    }

    std::string getSpriteName() { return defaultSpriteName; }

    void setDefaultSpriteName(std::string name) { defaultSpriteName = name; }

    int getZ() const { return z; }

protected:
    std::string defaultSpriteName;

    int z;
};


#endif //SPACEGAME_VISUALPROPERTIES_H
