//
// Created by SJ Holland on 8/30/16.
//

#include "CameraController.h"

void CameraController::setCameraOnCharacter(SDL_Rect & camera, Level & level, Character & character, int screen_width,
                                            int screen_height) {

    SDL_Rect characterBox = character.getCollisionBox();

    //Center the camera over the character
    camera.x = ( characterBox.x + characterBox.w / 2 ) - screen_width / 2;
    camera.y = ( characterBox.y + characterBox.h / 2 ) - screen_height / 2;

    int level_width = level.getWidth();
    int level_height = level.getHeight();

    //Keep the camera in bounds
    if( camera.x < 0 )
    {
        camera.x = 0;
    }
    if( camera.y < 0 )
    {
        camera.y = 0;
    }
    if( camera.x > level_width - camera.w )
    {
        camera.x = level_width - camera.w;
    }
    if( camera.y > level_height - camera.h )
    {
        camera.y = level_height - camera.h;
    }

}
