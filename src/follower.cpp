#include "stdlib.h"
#include "iostream"
#include <thread>
#include <chrono>

#include <GLFW/glfw3.h>

#include "window/window.h"
#include "world/world.h"

using namespace std;

double const FRAME_RATE = 120.0f;

int main() {

    if (!glfwInit()) {
        cerr << "[error]: glfw didn't init" << endl;
        exit(EXIT_FAILURE);
    }

    Window window;
    if (window.init() == EXIT_FAILURE) {
        exit(EXIT_FAILURE);
    }

    // create all needed objects
    World world;
    Printer printer;

    // render
    double lastRenderTime = 0.0;
    while (!window.shouldClose()) {
        // frame rate limit
        double currentTime = glfwGetTime();
        double deltaTime = currentTime - lastRenderTime;
        // skip rendering if frame time didn't come 
        if(deltaTime < (1.0 / FRAME_RATE)) {
            continue;
        }
        lastRenderTime = currentTime;

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