//
// Created by SJ Holland on 8/27/16.
//

#ifndef SPACEGAME_GAMEOBJECT_H
#define SPACEGAME_GAMEOBJECT_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <SDL_rect.h>
#include "Property.h"
#include "PhysicalProperties.h"
#include "EnemyAI.h"
#include "VisualProperties.h"
#include "HealthProperties.h"


class GameObject {

public:
    GameObject(std::string n):
            uuid(boost::uuids::random_generator()()),
            name(n),
            mBox(),
            physicalProperties(*this, 0, 0, left),
            visualProperties(*this),
            healthProperties(*this)
    {
        makeAI();
    }

    GameObject(std::string n, int x, int y, int w, int h):
            GameObject(n)
    {
        mBox.x = x;
        mBox.y = y;
        mBox.w = w;
        mBox.h = h;
    }

    // No copying
    GameObject(GameObject const & rhs) = delete;
    GameObject& operator = (GameObject const & rhs) = delete;

    virtual ~GameObject() {}

    bool operator == (GameObject const & rhs) { return uuid == rhs.uuid; }

    // Accessors
    const boost::uuids::uuid getUUID() const { return uuid; }

    virtual std::string getName() const { return name; }

    SDL_Rect getCollisionBox() const { return mBox; };

    bool collidesWith(GameObject & o);

    PhysicalProperties & getPhysicalProperties() { return physicalProperties; }

    VisualProperties & getVisualProperties() { return visualProperties; }

    HealthProperties & getHealthProperties() { return healthProperties; }

    // Mutators
    void setCollisionBox(SDL_Rect b);

    virtual void onLevelExit();

    virtual void onCollide(GameObject & o);

    virtual void updateState();

private:
    boost::uuids::uuid uuid;
    std::string name;

protected:
    SDL_Rect mBox;
    PhysicalProperties physicalProperties;
    VisualProperties visualProperties;
    HealthProperties healthProperties;
    std::unique_ptr<AI> aiPtr;

    virtual void makeAI() { aiPtr = std::unique_ptr<AI>(new AI(*this)); }
};


#endif //SPACEGAME_GAMEOBJECT_H
