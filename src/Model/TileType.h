//
// Created by SJ Holland on 5/22/16.
//

#ifndef SDTTEST_TILETYPE_H
#define SDTTEST_TILETYPE_H


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


#endif //SDTTEST_TILETYPE_H
