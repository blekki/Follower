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
    double lastCalcTime = 0.0f;

    const uint DOTS_COUNT = 1000;

public:
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

    void setAttractorPos(Coord pos) {
        this->attractor = pos;
    }

    Coord getAttractorPos() {
        return attractor;
    }

    // other methods
    void updateFolowers() {
        // use delta-time as correlation coef of attraction
        double currentTime = glfwGetTime();
        double deltaTime = currentTime - lastCalcTime;
        this->lastCalcTime = currentTime;

        for (uint i = 0; i < DOTS_COUNT; i++) {
            followers[i].addAttractionFluence(attractor, deltaTime);
            followers[i].updatePos();
        }
    }

    vector<Dot>* getFollowers() {
        return &followers;
    }
};