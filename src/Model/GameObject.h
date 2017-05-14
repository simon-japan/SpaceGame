//
// Created by SJ Holland on 8/27/16.
//

#ifndef SPACEGAME_GAMEOBJECT_H
#define SPACEGAME_GAMEOBJECT_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <SDL_rect.h>
#include "Property.h"


class GameObject {

public:
    // Constructors
    GameObject(std::string n):
            uuid(boost::uuids::random_generator()()),
            name(n),
            mBox(),
            blocked(false),
            properties()
    {
        properties.push_back(std::unique_ptr<>)
    }

    // Copy constructor
    GameObject(GameObject const & rhs):
            uuid(rhs.uuid),
            name(rhs.name),
            mBox(rhs.mBox),
            blocked(rhs.blocked),
            tangible(rhs.tangible) {}

    // Copy assignment
    GameObject& operator = (GameObject const & rhs)
    {
        uuid = rhs.uuid;
        name = rhs.name;
        mBox = rhs.mBox;
        blocked = rhs.blocked;
        tangible = rhs.tangible;
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

    bool isBlocked() const;

    bool collidesWith(GameObject & o);

    // Mutators

    void setCollisionBox(SDL_Rect b);

    void setBlocked(bool b);

    virtual void onLevelExit();

    virtual void onCollide(GameObject & o);

    virtual void updateState();

private:
    boost::uuids::uuid uuid;
    std::string name;
    std::vector<std::unique_ptr<Property>> properties;

protected:
    bool tangible;
    SDL_Rect mBox;
    bool blocked;

};


#endif //SPACEGAME_GAMEOBJECT_H
