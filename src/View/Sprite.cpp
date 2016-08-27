//
// Created by SJ Holland on 4/6/16.
//

#include <iostream>
#include <sstream>
#include "Sprite.h"

int Sprite::render(const int x, const int y, const int index, SDL_Renderer *sdlRenderer) {
    if(index >= clips.size())
    {
        std::ostringstream ostringstream;
        ostringstream << index << " is outside the bounds of the clip index: " << clips.size();
        throw std::invalid_argument(ostringstream.str());
    }
    else
    {
        clips[index].render(x, y, sdlRenderer);

        // Return the next clip index (possibly looping back to the beginning)
        if (index == clips.size() - 1)
        {
            return 0;
        }
        else
        {
            return index + 1;
        }
    }
}

int Sprite::render(SDL_Rect & target, const int index, SDL_Renderer *sdlRenderer) {
    if(index >= clips.size())
    {
        std::ostringstream ostringstream;
        ostringstream << index << " is outside the bounds of the clip index: " << clips.size();
        throw std::invalid_argument(ostringstream.str());
    }
    else
    {
        clips[index].render(target, sdlRenderer);

        // Return the next clip index (possibly looping back to the beginning)
        if (index == clips.size())
        {
            return 0;
        }
        else
        {
            return index + 1;
        }
    }
}

const std::string Sprite::getName() const{
    return name;
}

void Sprite::addClip(LTexture & texture, int x, int y, int w, int h) {
    SDL_Rect clip;
    clip.x = x;
    clip.y = y;
    clip.w = w;
    clip.h = h;
    clips.emplace_back(texture, clip);
}










