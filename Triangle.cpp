#include "Triangle.h"


Triangle::Triangle()
{
}


Triangle::Triangle(GLuint vertex1, GLuint vertex2, GLuint vertex3)
{
    verticesIndex.push_back(vertex1);
    verticesIndex.push_back(vertex2);
    verticesIndex.push_back(vertex3);
}


Triangle::~Triangle()
{
}


std::vector<GLuint> Triangle::getVerticesIndex() const
{
    return this->verticesIndex;
}


bool Triangle::hit(const Ray& ray, float distance_min, float distance_max, hitInfo& htInfo) override
{
    // Hit with a plane
    // point is in the triangle



    return false;
}


std::string Triangle::toString()
{
    std::stringstream sstr;

    sstr << "Triangle : (" << verticesIndex[0] << ", " << verticesIndex[1] << ", " << verticesIndex[2] << ")";

    return sstr.str();
}
