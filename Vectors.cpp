#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

void Constructors()
{
    std::cout << std::endl;

    glm::vec3 Point1{ 10.0f, 0.0f, 0.0f };

    std::cout << "Point1: " << glm::to_string(Point1) << std::endl;
}
int main() {
    
    Constructors();
    return 0;
}