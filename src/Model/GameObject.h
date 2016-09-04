//
// Created by SJ Holland on 8/27/16.
//

#ifndef SPACEGAME_GAMEOBJECT_H
#define SPACEGAME_GAMEOBJECT_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <SDL_rect.h>

class GameObject {

public:
    GameObject(std::string n): uuid(boost::uuids::random_generator()()), name(n), mBox(), blocked(false) {}

    GameObject(GameObject const & rhs): uuid(rhs.uuid), name(rhs.name), mBox(rhs.mBox), blocked(rhs.blocked),
                                        tangible(rhs.tangible) {}

    bool operator == (GameObject const & rhs) { return uuid == rhs.uuid; }

    GameObject& operator = (GameObject const & rhs)
    {
        uuid = rhs.uuid;
        name = rhs.name;
        mBox = rhs.mBox;
        blocked = rhs.blocked;
        tangible = rhs.tangible;
        return *this;
    }

    const boost::uuids::uuid getUUID() const { return uuid; }

    virtual std::string getName() const { return name; }

    virtual bool isTangible() const { return tangible; }

    void setTangible(bool t) { tangible = t; }

    bool collidesWith(GameObject & o);

    SDL_Rect getCollisionBox() const { return mBox; };

    void setCollisionBox(SDL_Rect b);

    bool isBlocked() const;

    void setBlocked(bool b);

private:

    boost::uuids::uuid uuid;

    std::string name;

protected:
    bool tangible;

    SDL_Rect mBox;

    bool blocked;

};


#endif //SPACEGAME_GAMEOBJECT_H
