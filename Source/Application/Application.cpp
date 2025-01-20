#include <iostream>
#define GLFW_INCLUDE_NONE
#include "Window.h"
#include "../../Third_Party/GLAD/include/glad/glad.h"

int main() {

    Window::InitWindow(1080, 720, "First Rendering Engine");

    while (!glfwWindowShouldClose(Window::window)) {

        glad_glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
        glad_glClear(GL_COLOR_BUFFER_BIT);


        glfwSwapBuffers(Window::window);
        glfwPollEvents();
    }

    Window::CloseGLFW();

}