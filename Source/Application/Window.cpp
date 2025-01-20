#define GLFW_INCLUDE_NONE
#include "Window.h"
#include "../../Third_Party/GLAD/include/glad/glad.h"
#include "../../Third_Party/GLFW/glfw3.h"
#include <iostream>

//TODO: Finish window class



Window::Window() {
    glfwSetErrorCallback(ErrorCallback);
    if (!glfwInit()) {
        std::cout << "ERROR::WINDOW::MESSAGE - glfw failed to initialize" << std::endl;
    }
}

Window::~Window() {
    glfwTerminate();
}

void Window::InitWindow(int height, int width, const char* title) {
    Height = height;
    Width = width;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(Width, Height, title, nullptr, nullptr);

    glfwMakeContextCurrent(window);


    glfwSetKeyCallback(window, KeyCallback);
    glfwSetFramebufferSizeCallback(window, SizeCallback);
}

void Window::ErrorCallback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

void Window::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void Window::SizeCallback(GLFWwindow* window, int width, int height) {
    glad_glViewport(0, 0, width, height);
}
