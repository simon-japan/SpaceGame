//
// Created by SJ Holland on 2016/11/18.
//
// Based on this tutorial:
// [ https://gamedevelopment.tutsplus.com/tutorials/
//    quick-tip-use-quadtrees-to-detect-likely-collisions-in-2d-space--gamedev-374 ]

#ifndef SPACEGAME_QUADTREE_H
#define SPACEGAME_QUADTREE_H


#include <SDL_rect.h>
#include <vector>
#include <array>
#include "GameObject.h"

class QuadTree {

public:
    static const int MAX_OBJECTS = 10;  // How many objects a node can hold before it splits
    static const int MAX_LEVELS = 5;    // The deepest level sub-node

    QuadTree(int pLevel, SDL_Rect bounds):
            level(pLevel),
            bounds(bounds),
            nodes(),
            objects()
    {};

    // Clears the quadtree by recursively clearing all objects from all nodes.
    void clear();

    // Clear the QuadTree and also set new bounds
    void clear(SDL_Rect newBounds) { clear(); bounds = newBounds; }

    // Determines whether the node has any child nodes and tries to add the object there.
    // If there are no child nodes or the object doesn’t fit in a child node, it adds the object to the parent node.
    void insert(GameObject & pGameObject);

    // returns all objects in all nodes that the given object could potentially collide with.
    std::vector<GameObject> & retrieve(std::vector<GameObject> & returnObjects, GameObject & pObject);

private:
    // Splits the node into four subnodes by dividing the node into four equal parts
    // and initializing the four subnodes with the new bounds.
    void split();

    // Helper function. Determines where an object belongs in the quadtree by
    // determining which node the object can fit into.
    int getIndex(SDL_Rect pRect);

    int level;          // The current node level; 0 is the topmost
    SDL_Rect bounds;    // The 2D space that the node occupies
    std::array<std::unique_ptr<QuadTree>, 4> nodes; // Child nodes
    std::vector<GameObject&> objects;    // Game objects that are inside this node
};


#endif //SPACEGAME_QUADTREE_H
