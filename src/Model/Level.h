//
// Created by SJ Holland on 4/3/16.
//

#ifndef SPACEGAME_LEVEL_H
#define SPACEGAME_LEVEL_H


#include <vector>
#include <unordered_map>
#include "Tile.h"
#include "Character.h"
#include "QuadTree.h"

class Character;

enum Axis { Xaxis, Yaxis };

class Level {

public:
    Level(): max_x(0), min_x(0), max_y(0), min_y(0),
             collisionQuadTree(0, SDL_Rect{0,0,0,0}) {};
    void addTile(int x, int y, const TileType & tileType);
    void addCharacter(std::shared_ptr<Character> character);
    int getHeight();
    int getWidth();
    const std::vector<std::shared_ptr<Tile>> & getTiles() const { return tiles; };
    std::shared_ptr<Character> getCharacter(std::string name) { return characters[name]; }
    auto beginCharacters() { return characters.begin(); }
    auto endCharacters() { return characters.end(); }
    void moveCharacters();
    void tryMoveGameObject(GameObject & o, int amount, Axis axis);
    bool wouldCollide(SDL_Rect target, Axis axis, GameObject & o);
    void updateAI();


private:

    void refreshQuadTree();


    int max_x;
    int min_x;
    int max_y;
    int min_y;
    std::vector<std::shared_ptr<Tile>> tiles;
    std::unordered_map<std::string, std::shared_ptr<Character>> characters;
    QuadTree collisionQuadTree;
};


#endif //SPACEGAME_LEVEL_H
