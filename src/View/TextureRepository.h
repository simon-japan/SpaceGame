//
// Created by SJ Holland on 4/10/16.
//

#ifndef SDTTEST_TEXTUREREPOSITORY_H
#define SDTTEST_TEXTUREREPOSITORY_H


#include <map>
#include "LTexture.h"

class TextureRepository {

public:
    void addTexture(std::string name, std::unique_ptr<LTexture> texture);

    LTexture & getTexture(std::string name);

private:
    std::map<std::string, std::unique_ptr<LTexture>> textureDictionary;

};


#endif //SDTTEST_TEXTUREREPOSITORY_H
