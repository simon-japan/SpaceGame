//
// Created by SJ Holland on 4/5/16.
//

#ifndef SDTTEST_SPRITESHEET_H
#define SDTTEST_SPRITESHEET_H


#include <vector>
#include <map>
#include "LTexture.h"

class SpriteSheet {

public:
    SpriteSheet(LTexture * t): pTexture(t) {};

    // Add a rectangular clip to the sheet's clips, assigning a name to it.
    void addClip(const std::string name, const SDL_Rect clip);

    // Render the named clip to point x,y on the provided renderer.
    void render(const int x, const int y, SDL_Renderer *gRenderer, std::string name);

private:
    std::unique_ptr<LTexture> pTexture;
    std::map<std::string, SDL_Rect> clips;
};


#endif //SDTTEST_SPRITESHEET_H
