//
// Created by SJ Holland on 4/9/16.
//

#ifndef SDTTEST_SPRITELOADER_H
#define SDTTEST_SPRITELOADER_H


#include "../View/SpriteRepository.h"
#include "../View/TextureRepository.h"

class SpriteLoader {

public:
    // The input file will provide the following information:
    // - paths of image files to load
    // - for each image, one or more clips specified by four integers (the corners)
    // - define sprites that have names and one or more clips in a sequence (each clip belongs to a sprite)
    // The sprites, clips and images will get stored in the sprite repository.
    int loadSprites(std::string filename, SpriteRepository & spriteRepository,
                    TextureRepository & textureRepository, SDL_Renderer *renderer);

private:
    // Load a texture from a file and save it in the texture repository with the name provided. Transfers ownership
    // of the texture to the repository.
    // Return false if the loading failed.
    bool loadTexture(std::string fileName, std::string textureName, TextureRepository & textureRepository,
                     SDL_Renderer * renderer);

};


#endif //SDTTEST_SPRITELOADER_H
