//
// Created by SJ Holland on 8/27/16.
//

#ifndef SPACEGAME_GAMEOBJECT_H
#define SPACEGAME_GAMEOBJECT_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <SDL_rect.h>
#include "Property.h"
#include "Physical.h"
#include "EnemyAI.h"


class GameObject {

public:
    // Constructors
    GameObject(std::string n):
            uuid(boost::uuids::random_generator()()),
            name(n),
            mBox(),
            physical(*this, 0, 0, left),
            ai(*this)
    {}

    // Constructors
    GameObject(std::string n, int x, int y, int w, int h):
            GameObject(n)
    {
        mBox.x = x;
        mBox.y = y;
        mBox.w = w;
        mBox.h = h;
    }

    // Copy constructor
    GameObject(GameObject const & rhs):
            uuid(rhs.uuid),
            name(rhs.name),
            mBox(rhs.mBox),
            physical(*this,
                     rhs.physical.getXVelocity(),
                     rhs.physical.getYVelocity(),
                     rhs.physical.getFacingDirection()
            ),
            ai(*this)
    {}

    // Copy assignment
    GameObject& operator = (GameObject const & rhs)
    {
        uuid = rhs.uuid;
        name = rhs.name;
        mBox = rhs.mBox;
        return *this;
    }

    // Destructor
    virtual ~GameObject() {}

    // Comparison
    bool operator == (GameObject const & rhs) { return uuid == rhs.uuid; }

    // Accessors
    const boost::uuids::uuid getUUID() const { return uuid; }

    virtual std::string getName() const { return name; }

    SDL_Rect getCollisionBox() const { return mBox; };

    bool collidesWith(GameObject & o);

    Physical & getPhysical() { return physical; }

    // Mutators
    void setCollisionBox(SDL_Rect b);

    virtual void onLevelExit();

    virtual void onCollide(GameObject & o);

    virtual void updateState(Level & level);

private:
    boost::uuids::uuid uuid;
    std::string name;

protected:
    SDL_Rect mBox;
    Physical physical;
    EnemyAI ai;
};


#endif //SPACEGAME_GAMEOBJECT_H
