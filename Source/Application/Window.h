#ifndef WINDOW_H
#define WINDOW_H

#include "../../Third_Party/GLFW/glfw3.h"
#include <stdio.h>

class Window {
public:
    static GLFWwindow* window;
    static int Height;
    static int Width;


    Window();
    ~Window();

    static void InitWindow(int height, int width, const char* title);


private:
    static bool _init;

    static void ErrorCallback(int error, const char* message);
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void SizeCallback(GLFWwindow* window, int width, int height);
};


#endif