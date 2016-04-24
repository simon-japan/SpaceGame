//
// Created by SJ Holland on 4/9/16.
//

#include "SpriteLoader.h"
#include "XmlDOMDocument.h"
#include <iostream>

using namespace std;
using namespace xercesc;

int SpriteLoader::loadSprites(std::string filename, SpriteRepository & spriteRepository,
                              TextureRepository & textureRepository, SDL_Renderer *renderer) {

    std::unique_ptr<XmlDomDocument> doc = std::unique_ptr<XmlDomDocument>(new XmlDomDocument(filename.c_str()));
    for (int i = 0; i < doc->getChildCount("textures", 0, "texture"); i++)
    {
        string textureName(doc->getChildAttribute("textures", 0, i, "texture", "name"));
        string textureFile(doc->getChildAttribute("textures", 0, i, "texture", "file"));
        loadTexture(textureFile, textureName, textureRepository, renderer);
        //std::unique_ptr<LTexture> pTexture (new LTexture());
        //pTexture->loadFromFile(textureFile, renderer);
        //textureRepository.addTexture(textureName, std::move(pTexture));
        for (int j = 0; j < doc->getChildCount("texture", i, "clip"); j++) {
            string clipID(doc->getChildAttribute("texture", i, j, "clip", "id"));
            int x = atoi(doc->getChildAttribute("texture", i, j, "clip", "x").c_str());
            int y = atoi(doc->getChildAttribute("texture", i, j, "clip", "y").c_str());
            int w = atoi(doc->getChildAttribute("texture", i, j, "clip", "w").c_str());
            int h = atoi(doc->getChildAttribute("texture", i, j, "clip", "h").c_str());
            LTexture & rtexture = textureRepository.getTexture(textureName);
            size_t clipIndex = rtexture.addClip(x, y, w, h);
            spriteRepository.addSprite(new Sprite(clipID, textureRepository.getTexture(textureName), 1, clipIndex));
            Sprite & sprite(spriteRepository.getSprite(clipID));
        }
    }
    return 0;
}

bool SpriteLoader::loadTexture(std::string fileName,
                               string textureName,
                               TextureRepository & textureRepository,
                               SDL_Renderer *renderer) {
    unique_ptr<LTexture> pTexture (new LTexture());
    if(!pTexture->loadFromFile(fileName, renderer))
    {
        cerr << "Failed to load texture " << textureName << " from file " << fileName << endl;
        return false;
    }
    textureRepository.addTexture(textureName, std::move(pTexture));
    return true;
}





