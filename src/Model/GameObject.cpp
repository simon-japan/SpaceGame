//
// Created by SJ Holland on 8/27/16.
//

#include "GameObject.h"
#include "Geometry.h"

bool GameObject::collidesWith(GameObject & o) {
    if (o.getUUID() == uuid)
    {
        return false;
    }
    return Geometry::checkCollision(mBox, o.getCollisionBox());
}

void GameObject::setCollisionBox(SDL_Rect b) {
    mBox = b;
}
