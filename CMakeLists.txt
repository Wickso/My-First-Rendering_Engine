cmake_minimum_required(VERSION 3.30.5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_STANDARD 23)

project(FirstRenderingEngine)

file(GLOB SOURCE
        "Source/Application/*.cpp"
        "Source/Application/*.h"
        "Source/Rendering/*.cpp"
        "Source/Rendering/*.h"
        "Source/Shader/*.cpp"
        "Source/Shader/*h"
)

file(GLOB THIRD_PARTY
        "Third_Party/GLAD/src/glad.c"
        "Third_Party/**.h"
)

add_library(GLFW STATIC IMPORTED)
set_property(TARGET GLFW PROPERTY IMPORTED_LOCATION "../Third_Party/GLFW/libglfw3.a")
add_library(OPENGL STATIC IMPORTED)
set_property(TARGET OPENGL PROPERTY IMPORTED_LOCATION "../Third_Party/OpenGL/OpenGL32.Lib")

add_executable(FirstEngine ${SOURCE} ${THIRD_PARTY})

target_link_libraries(FirstEngine
        PUBLIC GLFW OPENGL
)

