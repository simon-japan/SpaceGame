//
// Created by SJ Holland on 8/28/16.
//

#include <SDL_events.h>
#include "GameController.h"

class Level;
class GameObject;
class Character;

using namespace std;

void GameController::handlePlayerInput(SDL_Event& e) {
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: player.setThrust(Direction::up, true); break;
            case SDLK_DOWN: player.setThrust(Direction::down, true); break;
            case SDLK_LEFT: player.setThrust(Direction::left, true); break;
            case SDLK_RIGHT: player.setThrust(Direction::right, true); break;
            case SDLK_SPACE: {
                SDL_Rect playerBounds = player.getCollisionBox();
                int x = playerBounds.x;
                int y = playerBounds.y;
                switch (player.getFacingDirection())
                {
                    case Direction::up: y += playerBounds.h; break;
                    case Direction::down: y -= playerBounds.h; break;
                    case Direction::left: x -= playerBounds.w; break;
                    default: x += playerBounds.w; break;
                }
                auto bulletPtr(make_shared<Character>(20, 20, x, y, "bullet"));
                bulletPtr->setThrust(player.getFacingDirection(), true);
                level.addCharacter(bulletPtr);
                break;
            }
            default:break;
        }
    }
        //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: player.setThrust(Direction::up, false); break;
            case SDLK_DOWN: player.setThrust(Direction::down, false); break;
            case SDLK_LEFT: player.setThrust(Direction::left, false); break;
            case SDLK_RIGHT: player.setThrust(Direction::right, false); break;
            default:break;
        }
    }
}
