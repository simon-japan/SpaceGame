//
// Created by SJ Holland on 8/30/16.
//

#ifndef SPACEGAME_CAMERACONTROLLER_H
#define SPACEGAME_CAMERACONTROLLER_H


#include <SDL_rect.h>
#include "../Model/Level.h"

class CameraController {
public:
    //Centers the camera over the character
    static void setCameraOnCharacter(SDL_Rect & camera, Level & level, GameObject & character,
                              int screen_width, int screen_height);

};


#endif //SPACEGAME_CAMERACONTROLLER_H
