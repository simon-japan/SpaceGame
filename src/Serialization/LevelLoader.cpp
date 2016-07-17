//
// Created by SJ Holland on 5/16/16.
//

#include <vector>
#include <fstream>
#include <sstream>
#include "XmlDOMDocument.h"
#include "LevelLoader.h"
#include <boost/tokenizer.hpp>
#include <iostream>

using namespace std;
using namespace xercesc;
using namespace boost;

unique_ptr<Level> LevelLoader::loadLevel(std::string filename) {

    loadTileTypes(filename);

    //The tile offsets
    int x = 0, y = 0;

    unique_ptr<Level> levelPointer(new Level());

    XmlDomDocument doc (filename.c_str());

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
            x += 1;
        }

        if (tokens.begin() != tokens.end()) {
            y += 1;
        }

    }

    return levelPointer;
}

void LevelLoader::loadTileTypes(std::string filename) {
    XmlDomDocument doc (filename.c_str());
    for (int i = 0; i < doc.getChildCount("tileTypes", 0, "tileType"); i++) {
        string spriteName(doc.getChildAttribute("tileTypes", 0, i, "tileType", "sprite"));
        int mapId(atoi(doc.getChildAttribute("tileTypes", 0, i, "tileType", "mapid").c_str()));
        bool tangible = false;
        if (doc.getChildAttribute("tileTypes", 0, i, "tileType", "tangible") != "false")
        {
            tangible = true;
        }
        tileTypeLookup.emplace(make_pair(mapId, TileType(spriteName, tangible)));
    }
}




