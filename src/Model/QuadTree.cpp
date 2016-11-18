//
// Created by SJ Holland on 2016/11/18.
//

#include "QuadTree.h"

void QuadTree::clear() {
    objects.clear();

    for(int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i] != nullptr) {
            nodes[i]->clear();
            nodes[i].reset();
        }
    }
}

/*
 * Insert the object into the quadtree. If the node
 * exceeds the capacity, it will split and add all
 * objects to their corresponding nodes.
 */
void QuadTree::insert(GameObject & pGameObject) {
    if (nodes[0] != nullptr)
    {
        int index(getIndex(pGameObject.getCollisionBox()));
        if (index != -1)
        {
            nodes[index]->insert(pGameObject);
            return;
        }
    }

    objects.push_back(pGameObject);

    if (objects.size() > MAX_OBJECTS && level < MAX_LEVELS)
    {
        if (nodes[0] == nullptr)
        {
            split();
        }

        size_t i = 0;
        while (i < objects.size())
        {
            int index(getIndex(objects.at(i).getCollisionBox()));
            if (index != -1)
            {
                nodes[index]->insert(objects[index]);
                objects.erase(objects.begin() + index);
            }
            else
            {
                i++;
            }
        }
    }
}

std::vector<GameObject> & QuadTree::retrieve(std::vector<GameObject> & returnObjects, GameObject & pObject) {
    int index(getIndex(pObject.getCollisionBox()));
    if (index != -1 && nodes[0] != nullptr)
    {
        nodes[index]->retrieve(returnObjects, pObject);
    }

    return returnObjects;
}

void QuadTree::split() {
    int subWidth = bounds.w / 2;
    int subHeight = bounds.h /2;
    int x = bounds.x;
    int y = bounds.y;

    nodes[0] = new QuadTree(level+1, SDL_Rect{x + subWidth, y, subWidth, subHeight};
    nodes[1] = new QuadTree(level+1, SDL_Rect{x, y, subWidth, subHeight};
    nodes[2] = new QuadTree(level+1, SDL_Rect{x, y + subHeight, subWidth, subHeight};
    nodes[3] = new QuadTree(level+1, SDL_Rect{x + subWidth, y + subHeight, subWidth, subHeight};
}

/*
 * Determine which node the object belongs to. -1 means
 * object cannot completely fit within a child node and is part
 * of the parent node
 */
int QuadTree::getIndex(SDL_Rect pRect) {
    int index = -1;
    double verticalMidpoint = bounds.x + (bounds.w / 2);
    double horizontalMidpoint = bounds.y + (bounds.h / 2);

    // Object can completely fit within the top quadrants
    bool topQuadrant = (pRect.y < horizontalMidpoint && pRect.y + pRect.h < horizontalMidpoint);
    // Object can completely fit within the bottom quadrants
    bool bottomQuadrant = (pRect.y > horizontalMidpoint);

    // Object can completely fit within the left quadrants
    if (pRect.x < verticalMidpoint && pRect.x + pRect.w < verticalMidpoint) {
        if (topQuadrant) {
            index = 1;
        }
        else if (bottomQuadrant) {
            index = 2;
        }
    }
        // Object can completely fit within the right quadrants
    else if (pRect.x > verticalMidpoint) {
        if (topQuadrant) {
            index = 0;
        }
        else if (bottomQuadrant) {
            index = 3;
        }
    }

    return index;
}

