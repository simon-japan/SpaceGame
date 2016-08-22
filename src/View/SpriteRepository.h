//
// Created by SJ Holland on 4/9/16.
//

#ifndef SDTTEST_SPRITEREPOSITORY_H
#define SDTTEST_SPRITEREPOSITORY_H

#include <map>
#include "Sprite.h"

class SpriteRepository {

public:
    Sprite & getSprite(std::string name);

    void addSprite(std::unique_ptr<Sprite> sp);

private:
    std::map<std::string,std::unique_ptr<Sprite>> sprites;

};


#endif //SDTTEST_SPRITEREPOSITORY_H
