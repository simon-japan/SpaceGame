//
// Created by SJ Holland on 4/10/16.
//

#include "TextureRepository.h"

using namespace std;

void TextureRepository::addTexture(string name, unique_ptr<GameTexture> texture) {
    textureDictionary.insert(make_pair(name, move(texture)));
}

GameTexture & TextureRepository::getTexture(std::string name) {
    return *(textureDictionary.at(name));
}



