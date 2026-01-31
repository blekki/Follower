#include "stdlib.h"
#include "iostream"
#include <thread>
#include <chrono>

#include <GLFW/glfw3.h>

#include "window/window.h"
#include "world/world.h"

/* 
Uncomment the next definition command to use extended render "EXTENDED_MOD".
Can be used for debugging.
PS: Better use with only one dot simulation.
*/
// #define EXTENDED_MOD

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

    // prerender
    window.preparateScene();
    printer.setResolution(window.getWidth(), window.getHeight());
    printer.printFolowers(world.getFollowers());
    window.pollEvents();
    window.swapBuffers();

    // render
    double lastRenderTime = 0.0;
    while (!window.shouldClose()) {
        // frame preparations
        window.pollEvents();
        window.preparateScene();
        printer.setResolution(window.getWidth(), window.getHeight());

        // frame rate limit
        double currentTime = glfwGetTime();
        double deltaTime = currentTime - lastRenderTime;
        if(deltaTime < (1.0 / FRAME_RATE)) {    // skip rendering if frame time didn't come 
            continue;
        }
        lastRenderTime = currentTime;

        // check simulation status
        if (window.getSimStatus() == SIM_FREEZE) {
            continue;
        }

        // movement calculation
        world.setAttractorPos(window.getCursorPos());
        world.updateFolowers(deltaTime);

        // prepare buffer frame
        printer.printFolowers(world.getFollowers());
        
        #ifdef EXTENDED_MOD
            // print speed of the first dot
            Dot* dot = &world.getFollowers()->at(0);
            printer.printDotDirection(
                dot->getPos(), 
                dot->getSpeed()
            );
        #endif

        // finish frame
        window.swapBuffers();
        lastRenderTime += deltaTime;
    }

    // the last operations before exit
    window.destroy();
    clog << "[log]: code finished" << endl;
    glfwTerminate();
}