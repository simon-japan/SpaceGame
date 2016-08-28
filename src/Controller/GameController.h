//
// Created by SJ Holland on 8/28/16.
//

#ifndef SPACEGAME_GAMECONTROLLER_H
#define SPACEGAME_GAMECONTROLLER_H

#include <SDL_events.h>
#include "../Model/Character.h"

class GameController {
public:
    GameController(Character & p): player(p) {};
    void handlePlayerInput(SDL_Event& e);

private:
    Character & player;
};


#endif //SPACEGAME_GAMECONTROLLER_H
