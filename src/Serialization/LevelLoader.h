//
// Created by SJ Holland on 5/16/16.
//

#ifndef SPACEGAME_LEVELLOADER_H
#define SPACEGAME_LEVELLOADER_H


#include <string>
#include <vector>
#include "../Model/Tile.h"
#include "../View/SpriteRepository.h"
#include "../Model/Level.h"

class LevelLoader {

public:
    LevelLoader(SpriteRepository & s): spriteRepository(s), tileTypeLookup() {};

    std::unique_ptr<Level> loadLevel(std::string filename);

    void loadTileTypes(std::string filename);

private:
    SpriteRepository & spriteRepository;
    std::map<int, TileType> tileTypeLookup;

    const char SEPARATOR = '\n';
};


#endif //SPACEGAME_LEVELLOADER_H
