//
// Created by SJ Holland on 4/9/16.
//

#include "SpriteRepository.h"

Sprite & SpriteRepository::getSprite(std::string name) {
    return *sprites[name];
}

void SpriteRepository::addSprite(SpriteSheet & s, std::string n) {
    sprites[n] = std::unique_ptr<Sprite>(new Sprite(s, n));
}



