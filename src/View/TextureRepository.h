//
// Created by SJ Holland on 4/10/16.
//

#ifndef SPACEGAME_TEXTUREREPOSITORY_H
#define SPACEGAME_TEXTUREREPOSITORY_H


#include <map>
#include "GameTexture.h"

class TextureRepository {

public:
    void addTexture(std::string name, std::unique_ptr<GameTexture> texture);

    GameTexture & getTexture(std::string name);

private:
    std::map<std::string, std::unique_ptr<GameTexture>> textureDictionary;

};


#endif //SPACEGAME_TEXTUREREPOSITORY_H
