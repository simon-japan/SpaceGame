//
// Created by SJ Holland on 8/28/16.
//

#ifndef SPACEGAME_GAMECONTROLLER_H
#define SPACEGAME_GAMECONTROLLER_H

#include <SDL_events.h>
#include "../Model/GameObject.h"
#include "../Model/Level.h"

class GameController {
public:
    GameController(GameObject & p, Level & l): player(p), level(l) {};
    void handlePlayerInput(SDL_Event& e);

private:
    GameObject & player;
    Level & level;
};


#endif //SPACEGAME_GAMECONTROLLER_H
