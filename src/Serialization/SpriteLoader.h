//
// Created by SJ Holland on 4/9/16.
//

#ifndef SPACEGAME_SPRITELOADER_H
#define SPACEGAME_SPRITELOADER_H


#include "../View/SpriteRepository.h"
#include "../View/TextureRepository.h"

class SpriteLoader {

public:
    SpriteLoader(TextureRepository& t, SpriteRepository& s, SDL_Renderer* r):
            textureRepository(t), spriteRepository(s), sdl_renderer(r) {}

    // The input file will provide the following information:
    // - paths of image files to load
    // - for each image, one or more clips specified by four integers (the corners)
    // - define sprites that have names and one or more clips in a sequence (each clip belongs to a sprite)
    // The sprites, clips and images will get stored in the sprite repository.
    int loadSprites(std::string config_file_name);

private:
    // Load a texture from a file and save it in the texture repository with the name provided. Transfers ownership
    // of the texture to the repository.
    // Return false if the loading failed.
    bool loadTexture(std::string fileName, std::string textureName);

    TextureRepository& textureRepository;
    SpriteRepository& spriteRepository;
    SDL_Renderer* sdl_renderer;
};


#endif //SPACEGAME_SPRITELOADER_H
