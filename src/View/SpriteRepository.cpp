//
// Created by SJ Holland on 4/9/16.
//

#include "SpriteRepository.h"

using namespace std;

Sprite & SpriteRepository::getSprite(string name) {
    return *(sprites.at(name));
}

void SpriteRepository::addSprite(Sprite * s) {
    string name = s->getName();
    sprites.insert(make_pair(name, unique_ptr<Sprite>(s)));
}



