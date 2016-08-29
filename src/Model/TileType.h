//
// Created by SJ Holland on 5/22/16.
//

#ifndef SPACEGAME_TILETYPE_H
#define SPACEGAME_TILETYPE_H


#include <string>

class TileType {

public:
    TileType(std::string n, bool t): name(n), tangible(t) {}
    const std::string getName() const {return name;}
    const bool isTangible() const {return tangible;}

private:
    std::string name;
    bool tangible;

};


#endif //SPACEGAME_TILETYPE_H
