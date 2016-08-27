//
// Created by SJ Holland on 4/9/16.
//

#include "SpriteRepository.h"

using namespace std;

Sprite * SpriteRepository::getSprite(string name) {
    if (sprites.find( name ) == sprites.end())
    {
        throw std::invalid_argument(name + " is not a valid sprite name");
    }
    return &(*sprites.at(name));
}

void SpriteRepository::addSprite(std::unique_ptr<Sprite> sp) {
    string name = sp->getName();
    sprites.insert(make_pair(name, std::move(sp)));
}



