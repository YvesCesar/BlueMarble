#include <iostream>
#include <cassert>
#include <array>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

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
    std::cout << "OpenGL Version   : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL Version     : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    // Definir um triângulo em coordenadas normalizadas
    std::array<glm::vec3, 3> Triangle = {
        glm::vec3{ -1.0f, -1.0f, 0.0f },
        glm::vec3{  1.0f, -1.0f, 0.0f },
        glm::vec3{  0.0f,  1.0f, 0.0f }
    };

    // Model Matrix
    glm::mat4 ModelMatrix = glm::identity<glm::mat4>();

    // View Matrix
    glm::vec3 Eye{ 0, 0, 5 };
    glm::vec3 Center{ 0, 0, 0 };
    glm::vec3 Up{ 0, -1, 0 };
    glm::mat4 ViewMatrix = glm::lookAt(Eye, Center, Up);

    // Projection Matrix
    constexpr float FoV = glm::radians(45.0f);
    const float AspectRatio = WIDTH / HEIGHT;
    const float Near = 0.001f;
    const float Far = 1000.0f;
    glm::mat4 ProjectionMatrix = glm::perspective(FoV, AspectRatio, Near, Far);

    // ModelViewProjection
    glm::mat4 ModelViewProjection = ProjectionMatrix * ViewMatrix * ModelMatrix;

    // Aplicar a ModelViewProjection nos vértices do triângulo
    for (glm::vec3& Vertex : Triangle)
    {
        glm::vec4 ProjectedVertex = ModelViewProjection * glm::vec4{ Vertex, 1.0f };
        ProjectedVertex /= ProjectedVertex.w;
        Vertex = ProjectedVertex;
    }

    // Agora, vamos copiar os vértices do triângulo para a memória da GPU
    GLuint VertexBuffer;

    // Pedir para o OpenGL gerar o identificador do VertexBuffer
    glGenBuffers(1, &VertexBuffer);

    // Ativar o VertexBuffer como sendo o buffer para onde vamos copiar os dados do triângulo
    glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

    // Copiar os dados para memória de vídeo
    glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle), Triangle.data(), GL_STATIC_DRAW);

    // Definir a cor de fundo 
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

    // Entra no loop de eventos da aplicação
    while (!glfwWindowShouldClose(window))
    {
        // glClear vai limpar o framebuffer. GL_COLOR_BUFFER_BIT limpa o buffer de cor. Depois de limpar, vai preencher com a cor que foi configurada no glClearColor
        // Quando formos desenhar geometrias 3D, vamos voltar ao glClear porque teremos que limpar o buffer de profundidade (depth buffer)
        glClear(GL_COLOR_BUFFER_BIT);

        glEnableVertexAttribArray(0);

        // glBindBuffer() Diz para o OpenGL que o VertexBuffer vai ser o buffer ativo do momento
        glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

        // glVertexAttribPointer() Informa ao OpenGL onde, dentro do VertexBuffer, os vértices estão.
        // No caso o array Triangles é contíguo em memória. Logo, basta dizer quantos vértices vamos usar para desenhar o triângulo
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        // glDrawArrays() diz para o OpenGL desenhar o triângulo com os dados que estão armazenados no VertexBuffer
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Reverter os estados criados
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDisableVertexAttribArray(0);

        // glfwPollEvents() Processa todos os eventos na fila de eventos do GLFW
        // Esses eventos podem ser do teclado, mouse, gamepad
        glfwPollEvents();

        // Envia o conteúdo do framebuffer da janela para ser desenhado na tela
        glfwSwapBuffers(window);
    }

    // Desalocar o VertexBuffer
    glDeleteBuffers(1, &VertexBuffer);

    // Encerra a biblioteca glfw
    glfwTerminate();
    return 0;
}