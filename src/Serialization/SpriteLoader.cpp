//
// Created by SJ Holland on 4/9/16.
//

#include "SpriteLoader.h"
#include "XmlDOMDocument.h"
#include <iostream>

using namespace std;
using namespace xercesc;

int SpriteLoader::loadSprites(std::string config_file_name) {
    // Load sprite config
    XmlDomDocument doc(config_file_name.c_str());
    if (!doc.loadedSuccessfully())
    {
        return -1;
    }

    // Textures need to be loaded before we can load the sprites / clips that refer to them
    for (int i = 0; i < doc.getChildCount("textures", 0, "texture"); i++)
    {
        string textureName(doc.getChildAttribute("textures", 0, i, "texture", "name"));
        string textureFile(doc.getChildAttribute("textures", 0, i, "texture", "file"));
        if (!loadTexture(textureFile, textureName))
        {
            return false;
        }
    }

    // Load the sprites and store them in the sprite repository
    for(int i = 0; i < doc.getChildCount("sprites", 0, "sprite"); i++)
    {
        string spriteName(doc.getChildAttribute("sprites", 0, i, "sprite", "name"));
        std::unique_ptr<Sprite> sprite_p(new Sprite(spriteName));
        for(int j = 0; j < doc.getChildCount("sprite", i, "clip"); j++) {
            string textureName(doc.getChildAttribute("sprite", i, j, "clip", "texture"));
            GameTexture & rtexture = textureRepository.getTexture(textureName);
            int x = atoi(doc.getChildAttribute("sprite", i, j, "clip", "x").c_str());
            int y = atoi(doc.getChildAttribute("sprite", i, j, "clip", "y").c_str());
            int w = atoi(doc.getChildAttribute("sprite", i, j, "clip", "w").c_str());
            int h = atoi(doc.getChildAttribute("sprite", i, j, "clip", "h").c_str());
            sprite_p->addClip(rtexture, x, y, w, h);
        }
        spriteRepository.addSprite(std::move(sprite_p));
    }
    return 0;
}

bool SpriteLoader::loadTexture(std::string fileName, string textureName) {
    unique_ptr<GameTexture> pTexture (new GameTexture());
    if(!pTexture->loadFromFile(fileName, sdl_renderer))
    {
        // Todo: proper logging
        cerr << "Failed to load texture " << textureName << " from file " << fileName << endl;
        return false;
    }
    textureRepository.addTexture(textureName, std::move(pTexture));
    return true;
}




