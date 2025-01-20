#define GLFW_INCLUDE_NONE
#include "Window.h"
#include "../../Third_Party/GLAD/include/glad/glad.h"
#include "../../Third_Party/GLFW/glfw3.h"
#include <iostream>

//TODO: Finish window class

int Window::Height;
int Window::Width;
GLFWwindow *Window::window;


void Window::InitWindow(int width, int height, const char *title) {
    Height = height;
    Width = width;
    glfwSetErrorCallback(ErrorCallback);
    if (!glfwInit()) {
        std::cout << "ERROR::WINDOW::MESSAGE - glfw failed to initialize" <<
            std::endl;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        std::cout << "ERROR::WINDOW::MESSAGE - Window failed to create" <<
            std::endl;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "ERROR::WINDOW::GLAD::MESSAGE - GLAD failed to load" <<
            std::endl;
    }
    glad_glViewport(0, 0, width, height);

    glfwSwapInterval(1);

    glfwSetKeyCallback(window, KeyCallback);
    glfwSetFramebufferSizeCallback(window, SizeCallback);
}

void Window::CloseGLFW() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::ErrorCallback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

void Window::KeyCallback(GLFWwindow *window, int key, int scancode, int action,
                         int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void Window::SizeCallback(GLFWwindow *window, int width, int height) {
    glad_glViewport(0, 0, width, height);
}