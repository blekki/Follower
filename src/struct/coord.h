#pragma once
#include "stdlib.h"
#include "math.h"

using namespace std;

// Coord unit equals 1 meter
struct Coord
{
    float x;
    float y;

    // constructor
    Coord() : x(0.0f), y(0.0f) {}; // default
    Coord(float x, float y) : x(x), y(y) {};

    // methods
    void normilize() {
        float length = sqrt(x*x + y*y);
        if (length != 0) {
            float k = 1.0f / length;
            this->x *= k;
            this->y *= k;
        }
    }

    float len() {
        return sqrt(x*x + y*y);
    }

    Coord operator+(Coord other) {
        return Coord(
            this->x + other.x, 
            this->y + other.y
        );
    }

    Coord operator-(Coord other) {
        return Coord(
            this->x - other.x, 
            this->y - other.y
        );
    }

    void operator+=(Coord other) {
        this->x += other.x; 
        this->y += other.y;
    }

    Coord operator/(float value) {
        return Coord(
            this->x /= value,
            this->y /= value
        );
    }

    Coord operator*(float value) {
        return Coord(
            this->x *= value,
            this->y *= value
        );
    }
};