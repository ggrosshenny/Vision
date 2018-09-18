#ifndef __TRIANGLE_H
#define __TRIANGLE_H


// Graphics
// - GLEW (always before "gl.h")
#include <GL/glew.h>
// - GL
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
// - GLUT
#include <GL/glut.h>

// glm
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Ray.h"

#include <vector>
#include <iostream>
#include <sstream>

// structs used to store mesh data

/**
 * @brief The Vertex struct is used to modelise a vertex with all its data
 */
struct Vertex
{
    /// Position of the vertex
    glm::vec3 position;
    /// Normal of the vertex
    glm::vec3 normal;
    /// testure coordinates of the vertex
    glm::vec2 textCoords;
};


class Triangle : public hitable
{
private:
    std::vector<GLuint> verticesIndex;


// Constructors and destructors
public:

    Triangle();

    Triangle(GLuint vertex1, GLuint vertex2, GLuint vertex3);

    ~Triangle();


// main methods
public:

    /**
     * @brief getVerticesIndex return the list of vertices index
     * @return
     */
    std::vector<GLuint> getVerticesIndex() const;


    bool hit(const Ray& ray, float distance_min, float distance_max, hitInfo& htInfo) override;


    std::string toString();

};

// External operator from class Triangle

template<typename T>
std::ostream& operator<<(std::ostream& os, Triangle& obj)
{
    os << obj.toString();
    return os;
}


#endif
