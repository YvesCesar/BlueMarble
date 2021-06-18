#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

void Constructors()
{
    std::cout << std::endl;

    // Na computação gráfica, utiliza-se uma geometria afim
    glm::vec2 Point0{ 10.0f, 10.0f };
    glm::vec3 Point1{ 10.0f, 0.0f, 0.0f };
    glm::vec4 Point2{ 10.0f, 10.0f, 0.0f, 0.0f };
    glm::ivec2 Point3 { 3, 4 };
    glm::bvec3 Point4 { false, true, false };
    glm::dvec2 Point5 { 10.0, 10.0 }; // dvec2 possui precisão dupla(2x mais preciso em relação ao vec2)

    std::cout << "Point0: " << glm::to_string(Point0) << std::endl;
    std::cout << "Point1: " << glm::to_string(Point1) << std::endl;
    std::cout << "Point2: " << glm::to_string(Point2) << std::endl;
    std::cout << "Point3: " << glm::to_string(Point3) << std::endl;
    std::cout << "Point4: " << glm::to_string(Point4) << std::endl;
    std::cout << "Point5: " << glm::to_string(Point5) << std::endl; 
}

int main() {
    
    Constructors();
    return 0;
}