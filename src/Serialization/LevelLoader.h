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
#include "XmlDOMDocument.h"

class LevelLoader {

public:
    LevelLoader() : tileTypeLookup() {};

    std::unique_ptr<Level> loadLevel(std::string filename);

private:
    std::map<int, TileType> tileTypeLookup;

    const char SEPARATOR = '\n';

    void loadTileTypes(XmlDomDocument & doc);

    void loadCharacters(XmlDomDocument & doc, Level & level);
};


#endif //SPACEGAME_LEVELLOADER_H
