#include "stdlib.h"
#include "iostream"
#include <thread>
#include <chrono>

#include <GLFW/glfw3.h>

#include "window/window.h"
#include "world/world.h"

using namespace std;

int main() {

    if (!glfwInit()) {
        cerr << "[error]: glfw didn't init" << endl;
        exit(EXIT_FAILURE);
    }

    Window window;
    if (window.init() == EXIT_FAILURE) {
        exit(EXIT_FAILURE);
    }

    World world;
    Printer printer;

    while (!window.shouldClose()) {
        // frame preparations
        window.preparateScene();
        printer.setResolution(window.getWidth(), window.getHeight());

        // movement calculation
        world.setAttractorPos(window.getCursorPos());
        world.updateFolowers();

        // prepare buffer frame
        printer.printFolowers(world.getFollowers());
        printer.printRadiusVec(world.getAttractorPos());

        // finish frame
        window.pollEvents();
        window.swapBuffers();
    }

    // the last operations before exit
    window.destroy();
    clog << "[log]: code finished" << endl;
    glfwTerminate();
}