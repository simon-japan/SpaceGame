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
    physicalProperties.setBlocked(true);
    if (getName().compare("bullet") == 0)
    {
        healthProperties.takeHit(100);
    }
}

void GameObject::onCollide(GameObject & o) {
    // todo: this sucks
    if (o.getName().compare("bullet") == 0)
    {
        healthProperties.takeHit(o.healthProperties.getAttackPower());
    }
    if (getName().compare("bullet") == 0)
    {
        healthProperties.takeHit(100);
    }
}

void GameObject::updateState() {
    if (name.compare("Player") != 0 ) {
        aiPtr->updateState();
    }
    physicalProperties.updateState();
    healthProperties.updateState();
    visualProperties.updateState();

}
