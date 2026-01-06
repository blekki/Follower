#pragma once

#include "stdlib.h"
#include <GLFW/glfw3.h>
#include "vector"

#include "coord.h"

using namespace std;

class Printer
{
private:
    int width;
    int height;

private:
    // convert into (-1 : 1) coord
    Coord as_ndc(Coord pos) {
        return Coord(
            pos.x * ( 2.0f / width),
            pos.y * (-2.0f / height)
        );
    }

public:
    Printer() {
        glPointSize(2);
    }
    
    // other methods
    void setResolution(int width, int height) {
        this->width = width;
        this->height = height;
    }

    void printDot(Coord dot) {
        Coord convDot = as_ndc(dot);
        glBegin(GL_POINTS);
        glVertex2d(convDot.x, convDot.y);
        glEnd();
    }

    void printFolowers(vector<Dot>* dots) {
        glBegin(GL_POINTS);
        for (uint i = 0; i < dots->size(); i++) {
            Coord convDot = as_ndc(dots->at(i).getPos());
            glVertex2d(convDot.x, convDot.y);
        }
        glEnd();
    }

    void printTestTrianle() {
        glBegin(GL_TRIANGLES);
        glVertex2d(0.0f, 0.0f);
        glVertex2d(1.0f, 0.0f);
        glVertex2d(1.0f, 1.0f);
        glEnd();
    }

    void printRadiusVec(Coord to) {
        to = as_ndc(to);
        glBegin(GL_LINES);
        glVertex2d(0.0f, 0.0f);
        glVertex2d(to.x, to.y);
        glEnd();
    }
};