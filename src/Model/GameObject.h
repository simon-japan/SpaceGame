//
// Created by SJ Holland on 8/27/16.
//

#ifndef SPACEGAME_GAMEOBJECT_H
#define SPACEGAME_GAMEOBJECT_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

class GameObject {

public:
    GameObject(std::string n): uuid(boost::uuids::random_generator()()), name(n) {}

    GameObject(GameObject const & rhs): uuid(rhs.uuid), name(rhs.name) {}

    bool operator == (GameObject const & rhs) { return uuid == rhs.uuid; }

    GameObject& operator = (GameObject const & rhs)
    {
        uuid = rhs.uuid;
        name = rhs.name;
        return *this;
    }

    const boost::uuids::uuid getUUID() const { return uuid; }

    virtual std::string getName() const { return name; }

private:

    boost::uuids::uuid uuid;

    std::string name;

};


#endif //SPACEGAME_GAMEOBJECT_H
