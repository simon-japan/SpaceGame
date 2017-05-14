//
// Created by SJ Holland on 5/16/16.
//

#include <vector>
#include <fstream>
#include <sstream>
#include "LevelLoader.h"
#include <boost/tokenizer.hpp>
#include <iostream>

using namespace std;
using namespace xercesc;
using namespace boost;

unique_ptr<Level> LevelLoader::loadLevel(std::string filename) {

    //The tile offsets
    int x = 0, y = 0;

    unique_ptr<Level> levelPointer(new Level());

    XmlDomDocument doc (filename.c_str());

    if (!doc.loadedSuccessfully())
    {
        return nullptr;
    }

    loadTileTypes(doc);

    loadCharacters(doc, *levelPointer);

    string map_string = doc.getChildValue("root", 0, "map", 0);
    stringstream ss(map_string);
    string line;

    while (getline(ss, line, SEPARATOR))
    {
        char_separator<char> sep(" ");
        tokenizer<char_separator<char>> tokens(line, sep);

        x = 0;

        for (const auto & t : tokens)
        {
            int tileTypeNumber = 0;
            stringstream convert(t);
            convert >> tileTypeNumber;
            auto it = tileTypeLookup.find(tileTypeNumber);
            if (it != tileTypeLookup.end())
            {
                const TileType & tt = it->second;
                levelPointer->addTile( x, y, tt);
            }
            else
            {
                cout << "Could not find Tile Type: " << tileTypeNumber << endl;
            }
            x += TILE_WIDTH;
        }

        if (tokens.begin() != tokens.end()) {
            y += TILE_HEIGHT;
        }
    }

    return levelPointer;
}

void LevelLoader::loadTileTypes(XmlDomDocument & doc) {
    for (int i = 0; i < doc.getChildCount("tileTypes", 0, "tileType"); i++) {
        string spriteName(doc.getChildAttribute("tileTypes", 0, i, "tileType", "sprite"));
        int mapId(atoi(doc.getChildAttribute("tileTypes", 0, i, "tileType", "mapid").c_str()));
        bool tangible = false;
        if (doc.getChildAttribute("tileTypes", 0, i, "tileType", "tangible") != "false")
        {
            tangible = true;
        }
        tileTypeLookup.emplace(mapId, TileType(spriteName, tangible));
    }
}

void LevelLoader::loadCharacters(XmlDomDocument & doc, Level & level) {
    for (int i = 0; i < doc.getChildCount("Characters", 0, "Character"); i++) {
        string characterName(doc.getChildAttribute("Characters", 0, i, "Character", "name"));
        SDL_Rect characterRect;
        characterRect.w = atoi(doc.getChildAttribute("Character", i, 0, "Rect", "w").c_str());
        characterRect.h = atoi(doc.getChildAttribute("Character", i, 0, "Rect", "h").c_str());
        characterRect.x = atoi(doc.getChildAttribute("Character", i, 0, "Rect", "x").c_str());
        characterRect.y =atoi(doc.getChildAttribute("Character", i, 0, "Rect", "y").c_str());
        auto characterP(make_shared<GameObject>(characterName));
        characterP->setCollisionBox(characterRect);
        level.addCharacter(characterP);
    }
}

