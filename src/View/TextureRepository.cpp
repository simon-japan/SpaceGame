//
// Created by SJ Holland on 4/10/16.
//

#include "TextureRepository.h"

using namespace std;

void TextureRepository::addTexture(string name, unique_ptr<LTexture> texture) {
    textureDictionary.insert(make_pair(name, move(texture)));
}

LTexture & TextureRepository::getTexture(std::string name) {
    return *(textureDictionary.at(name));
}



