#include <iostream>
#include <cassert>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

const int WIDTH = 800;
const int HEIGHT = 600;

int main() 
{
    // Inicializar a biblioteca GLFW
    assert(glfwInit());

    // Criar uma janela
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Blue Marble", nullptr, nullptr);
    assert(window);

    // Ativa o contexto criado na janela
    glfwMakeContextCurrent(window);

    // Inicializa a biblioteca GLEW
    assert(glewInit() == GLEW_OK);

    // Verifica a versão do OpenGL
    GLint GLMajorVersion = 0;
    GLint GLMinorVersion = 0;
    glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion);
    glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion);
    std::cout << "OpenGL Version: " << GLMajorVersion << "." << GLMinorVersion << std::endl;

    // Usa o glGetString() para obter informações do driver
    std::cout << "OpenGL Vendor    : " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "OpenGL Renderer  : " << glGetString(GL_RENDERER) << std::endl;

    // Entra no loop de eventos da aplicação
    while (!glfwWindowShouldClose(window))
    {
        // glfwPollEvents() Processa todos os eventos na fila de eventos do GLFW
        // Esses eventos podem ser do teclado, mouse, gamepad
        glfwPollEvents();

        // Envia o conteúdo do framebuffer da janela para ser desenhado na tela
        glfwSwapBuffers(window);
    }


    // Encerra a biblioteca glfw
    glfwTerminate();
    return 0;
}