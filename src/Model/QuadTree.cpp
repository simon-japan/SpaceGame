//
// Created by SJ Holland on 2016/11/18.
//

#include "QuadTree.h"

using namespace std;

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
void QuadTree::insert(std::shared_ptr<GameObject> pGameObject) {
    if (nodes[0] != nullptr)
    {
        int index(getIndex(pGameObject->getCollisionBox()));
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

        for (std::vector<std::shared_ptr<GameObject>>::iterator it = objects.begin();
                it != objects.end();)
        {
            int index(getIndex((*it)->getCollisionBox()));
            if (index != -1 && index < objects.size()) {
                nodes[index]->insert(*it);
                it->reset();
                it = objects.erase(it);
            }
            else
            {
                it++;
            }
        }
    }
}

vector<shared_ptr<GameObject>> & QuadTree::retrieve(vector<shared_ptr<GameObject>> & returnObjects, GameObject & pObject) {
    int index(getIndex(pObject.getCollisionBox()));
    if (index != -1 && nodes[0] != nullptr)
    {
        nodes[index]->retrieve(returnObjects, pObject);
    }

    returnObjects.insert(returnObjects.end(), objects.begin(), objects.end());

    return returnObjects;
}

void QuadTree::split() {
    int subWidth = bounds.w / 2;
    int subHeight = bounds.h /2;
    int x = bounds.x;
    int y = bounds.y;

    nodes[0].reset(new QuadTree(level+1, SDL_Rect{x + subWidth, y, subWidth, subHeight}));
    nodes[1].reset(new QuadTree(level+1, SDL_Rect{x, y, subWidth, subHeight}));
    nodes[2].reset(new QuadTree(level+1, SDL_Rect{x, y + subHeight, subWidth, subHeight}));
    nodes[3].reset(new QuadTree(level+1, SDL_Rect{x + subWidth, y + subHeight, subWidth, subHeight}));
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

std::ostream & operator<<(std::ostream & os, const QuadTree & t) {
    int indent = (t.level) * 4;
    while (indent > 0) {
        os << " ";
        indent--;
    }
    os << "NODE - objects (this node): " << t.objectsCount(false) << ", total: " << t.objectsCount(true)
       << ", level: " << t.level <<
       ", bounds: [x=" << t.bounds.x << ", y=" << t.bounds.y <<
       ", w=" << t.bounds.w << ", h=" << t.bounds.h << "]"<< endl;
    for (auto & o : t.objects)
    {
        indent = (t.level + 1) * 4;
        while (indent > 0) {
            os << " ";
            indent--;
        }
        SDL_Rect box = o->getCollisionBox();
        os << "GAMEOBJECT: " << "[x=" << box.x << ", y=" << box.y << ", w=" << box.w << ", h=" << box.h << "]" << endl;
    }
    for (auto & node : t.nodes)
    {
        if (node != nullptr)
            os << *node;
    }
    return os;
}

long QuadTree::objectsCount(bool includeChildren) const {
    if (includeChildren)
    {
        long total = objects.size();
        for (auto & node : nodes)
        {
            if (node != nullptr)
            {
                total += node->objectsCount(true);
            }
        }
        return total;
    }
    else
    {
        return objects.size();
    }

}
