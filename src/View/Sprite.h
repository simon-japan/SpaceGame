//
// Created by SJ Holland on 4/6/16.
//

#ifndef SDTTEST_SPRITE_H
#define SDTTEST_SPRITE_H

#include <vector>
#include "LTexture.h"
#include "Clip.h"

class Sprite {

public:
    Sprite(std::string n): name(n) {
        nextClipIndex = 0;
    };

    void addClip(LTexture& texture, int x, int y, int w, int h);

    void nextAnimationFrame();

    void render(const int x, const int y, SDL_Renderer* sdlRenderer);

    const std::string getName() const;

private:
    std::string name;
    std::vector<Clip> clips;
    int nextClipIndex;
    friend std::ostream& operator<<(std::ostream &, const Sprite&);
};

inline std::ostream& operator<<(std::ostream &os, const Sprite& s)
{
    return os << "Sprite(name:" << s.getName() << ", nextClipIndex:" << s.nextClipIndex << ")";
}

#endif //SDTTEST_SPRITE_H

