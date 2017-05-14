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

void GameObject::onLevelExit() {
    physical.setBlocked(true);
}

void GameObject::onCollide(GameObject & o) {

}

void GameObject::updateState(Level & level) {
    if (name.compare("Player") != 0 ) {
        ai.updateState();
    }
    physical.updateState(level);
}

