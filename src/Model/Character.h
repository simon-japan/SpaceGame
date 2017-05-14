/*
 Created by SJ Holland on 4/3/16.

 Represents an entity (player or NPC) that is capable of moving around the game world.
*/

#ifndef SPACEGAME_CHARACTER_H
#define SPACEGAME_CHARACTER_H

#include <SDL.h>
#include <vector>
#include "Tile.h"
#include "GameObject.h"

class Level;

class Character: public GameObject
{
public:

    Character(int w, int h, int startingX, int startingY, std::string n);

    ~Character() {}




    // Mutators

    void onCollide(GameObject & o);

    virtual void updateState();



};

#endif //SPACEGAME_CHARACTER_H
