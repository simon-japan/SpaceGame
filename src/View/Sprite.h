//
// Created by SJ Holland on 4/6/16.
//

#ifndef SDTTEST_SPRITE_H
#define SDTTEST_SPRITE_H


#include "SpriteSheet.h"

class Sprite {

public:
    Sprite(SpriteSheet & s, std::string n): sheet(s), name(n) {};
    void render(const int x, const int y, SDL_Renderer* gRenderer);
    std::string getName();

private:
    SpriteSheet& sheet;
    std::string name;
};


#endif //SDTTEST_SPRITE_H
