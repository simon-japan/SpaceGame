//
// Created by SJ Holland on 4/3/16.
//

#ifndef SPACEGAME_GEOMETRY_H
#define SPACEGAME_GEOMETRY_H

#include <SDL.h>

class Geometry {

public:

    static bool checkCollision( const SDL_Rect & a, const SDL_Rect & b );

};

#endif //SPACEGAME_GEOMETRY_H
