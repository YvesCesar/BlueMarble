#include <iostream>

#define GLM_FORCE_SWIZZLE 
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
    glm::vec3 Point6 { Point0, 1.0f };
    glm::vec2 Point7 { Point2 };

    std::cout << "Point0: " << glm::to_string(Point0) << std::endl;
    std::cout << "Point1: " << glm::to_string(Point1) << std::endl;
    std::cout << "Point2: " << glm::to_string(Point2) << std::endl;
    std::cout << "Point3: " << glm::to_string(Point3) << std::endl;
    std::cout << "Point4: " << glm::to_string(Point4) << std::endl;
    std::cout << "Point5: " << glm::to_string(Point5) << std::endl;
    std::cout << "Point6: " << glm::to_string(Point6) << std::endl;
    std::cout << "Point7: " << glm::to_string(Point7) << std::endl;  
}

void Components() {
    std::cout << std::endl;

    glm::vec4 P{ 1, 2, 3, 4 };
    std::cout << " X:" << P.x << " Y:" << P.y << " Z:" << P.z << std::endl;
    std::cout << " R:" << P.r << " G:" << P.g << " B:" << P.b << std::endl;
    std::cout << " 0:" << P[0] << " 1:" << P[1] << " 2:" << P[2] << std::endl;
}

void Swizzle() {
    std::cout << std::endl;

    glm::vec4 P{ 1, 2, 3, 4 };

    glm::vec3 Q = P.xxx();
    glm::vec3 R = P.xyx();
    glm::vec4 T = P.xyzw();
    glm::vec4 Y = P.xzzw();

    std::cout << glm::to_string(Y) << std::endl;
}

int main() {
    
    Constructors();
    Components();
    Swizzle();
    return 0;
}