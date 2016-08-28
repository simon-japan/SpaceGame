//
// Created by SJ Holland on 8/28/16.
//

#include <SDL_events.h>
#include "GameController.h"

void GameController::handlePlayerInput(SDL_Event& e) {
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: player.setThrust(up, true); break;
            case SDLK_DOWN: player.setThrust(down, true); break;
            case SDLK_LEFT: player.setThrust(left, true); break;
            case SDLK_RIGHT: player.setThrust(right, true); break;
            default:break;
        }
    }
        //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: player.setThrust(up, false); break;
            case SDLK_DOWN: player.setThrust(down, false); break;
            case SDLK_LEFT: player.setThrust(left, false); break;
            case SDLK_RIGHT: player.setThrust(right, false); break;
            default:break;
        }
    }
}
