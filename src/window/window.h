#pragma once
#include "stdlib.h"
#include "iostream"

#include <GLFW/glfw3.h>
#include "coord.h"

using namespace std;

class Window
{
private:
    GLFWwindow* window;
    int width = 640;
    int height = 480;

private:
    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
            cout << "*";
        }
    }

public:
    // construtor
    Window(){};
    ~Window(){};

    // other methods
    int init() {
        window = glfwCreateWindow(width, height, "Follower", NULL, NULL);
        if (!window) {
            window = nullptr;   // free pointer
            cerr << "[error]: window context creation failed" << endl;
            return EXIT_FAILURE;
        }
        glfwMakeContextCurrent(window);
        glfwSetKeyCallback(window, key_callback);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        return EXIT_SUCCESS;
    }

    void preparateScene() {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void pollEvents() { glfwPollEvents(); }
    void swapBuffers() { glfwSwapBuffers(window); }
    void destroy() { glfwDestroyWindow(window); }
    int shouldClose() { return glfwWindowShouldClose(window); }
    int getWidth()  { return width; }
    int getHeight() { return height; }

    Coord getCursorPos() {
        // screen cursor pos
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);

        // world cursor pos (in pixels)
        xPos = xPos - (width  / 2.0f);
        yPos = yPos - (height / 2.0f);

        return Coord(xPos, yPos);
    }
};
