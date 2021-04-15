cmake_minimum_required(VERSION 3.12)

project(BlueMarble)

add_executable(BlueMarble main.cpp)

if (WIN32)
    

else()
    find_package(glfw3 REQUIRED)
    find_package(GLEW REQUIRED)
    find_package(OpenGL REQUIRED)
 
    target_include_directories(BlueMarble PRIVATE deps/stb deps/glm)
    target_link_libraries(BlueMarble GLEW::glew
                                           glfw
                                           OpenGL::OpenGL)
endif()

add_executable(Vectors Vectors.cpp)
target_include_directories(Vectors PRIVATE deps/glm)

