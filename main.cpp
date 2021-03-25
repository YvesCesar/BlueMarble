#include <iostream>

#include <cassert>
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