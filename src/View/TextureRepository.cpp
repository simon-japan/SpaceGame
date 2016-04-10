//
// Created by SJ Holland on 4/10/16.
//

#include "TextureRepository.h"

using namespace std;

void TextureRepository::addTexture(string name, LTexture* texture) {
    textureDictionary.at(name) = unique_ptr<LTexture>(texture);
}

LTexture & TextureRepository::getTexture(std::string name) {
    return *(textureDictionary.at(name));
}



