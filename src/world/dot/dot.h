#pragma once
#include "stdlib.h"

#include "coord.h"

using namespace std;

class Dot
{
private:
    Coord pos;
    Coord speedVec;

public:
    // constructor
    Dot() {
        pos = Coord(0.0f, 0.0f);
        speedVec = Coord(0.0f, 0.0f);
    }

    Dot(Coord pos) {
        this->pos = pos;
        speedVec = Coord(0.0f, 0.0f);
    }

    // other methods
    Coord getPos()   { return pos; }
    Coord getSpeed() { return speedVec; }

    void updatePos() {
        pos += speedVec;
    }

    void addAttractionFluence(Coord attractorPos, double deltaTime) {
        const float VEC_LENGTHEN = 5.0f;

        Coord from = this->pos;
        Coord to   = attractorPos;

        Coord attraction;
        attraction = to - from;
        // make attraction the same for differ distances
        attraction.normilize();
        attraction *= VEC_LENGTHEN;

        this->speedVec += attraction * deltaTime;
    }
};