#pragma once

#include "stdlib.h"
#include "vector"

#include "coord.h"
#include "dot/dot.h"
#include "printer/printer.h"

using namespace std;

class World
{
private:
    vector<Dot> followers;
    Coord attractor;

    const uint DOTS_COUNT = 10000;

public:
    // constructor
    World() {
        uint range = 400;
        for (uint i = 0; i < DOTS_COUNT; i++) {
            Coord pos(
                rand() % range - (range / 2.0f),
                rand() % range - (range / 2.0f)
            );
            followers.push_back(Dot(pos));
        }
    }

    // other methods
    void setAttractorPos(Coord pos) {
        this->attractor = pos;
    }

    Coord getAttractorPos() {
        return attractor;
    }

    void updateFolowers(double deltaTime) { // deltaTime - delta-time from the last updating
        for (uint i = 0; i < DOTS_COUNT; i++) {
            followers[i].addAttractionFluence(attractor, deltaTime);
            followers[i].updatePos();
        }
    }

    vector<Dot>* getFollowers() {
        return &followers;
    }
};