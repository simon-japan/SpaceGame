//
// Created by SJ Holland on 4/6/16.
//

#ifndef SPACEGAME_SPRITE_H
#define SPACEGAME_SPRITE_H

#include <vector>
#include "GameTexture.h"
#include "Clip.h"

class Sprite {

public:
    Sprite(std::string n): name(n) {};

    void addClip(GameTexture& texture, int x, int y, int w, int h);

    int render(const int x, const int y, const int index, SDL_Renderer *sdlRenderer);

    int render(SDL_Rect & target, const int index, SDL_Renderer *sdlRenderer);

    const std::string getName() const;

private:
    std::string name;
    std::vector<Clip> clips;
    friend std::ostream& operator<<(std::ostream &, const Sprite&);
};

inline std::ostream& operator<<(std::ostream &os, const Sprite& s)
{
    return os << "Sprite(name:" << s.getName() << ")";
}

#endif //SPACEGAME_SPRITE_H

