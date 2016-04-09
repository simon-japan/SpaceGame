//
// Created by SJ Holland on 4/5/16.
//

#include "SpriteSheet.h"

void SpriteSheet::addClip(std::string name, SDL_Rect clip) {
    clips[name] = clip;
}

/*SDL_Rect SpriteSheet::getClip(const std::string name) const {
    return clips[name];
}*/

void SpriteSheet::render(const int x, const int y, SDL_Renderer *gRenderer, std::string name) {
    pTexture->render(x, y ,gRenderer, &clips[name]);
}





