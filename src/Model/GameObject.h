//
// Created by SJ Holland on 8/27/16.
//

#ifndef SPACEGAME_GAMEOBJECT_H
#define SPACEGAME_GAMEOBJECT_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

class GameObject {

public:
    GameObject(): uuid(boost::uuids::random_generator()()) {}

    GameObject(GameObject const & rhs): uuid(rhs.uuid) {}

    bool operator == (GameObject const & rhs) { return uuid == rhs.uuid; }

    GameObject& operator = (GameObject const & rhs)
    {
        uuid = rhs.uuid;
    }

    boost::uuids::uuid getUUID() { return uuid; }

private:

    boost::uuids::uuid uuid;

};


#endif //SPACEGAME_GAMEOBJECT_H
