#ifndef __RAY_H
#define __RAY_H

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


struct hitInfo
{
    float distance;
    glm::vec3 hitPoint;
    glm::vec3 normal;
};


/**
 * @brief The Ray class used to model a ray with a paramteric equation
 **/
class Ray
{
// attributes
public :
    glm::vec3 origin;
    glm::vec3 direction;


// constructors and destructors
public:

    /**
     * @brief Ray Default ray's origin is (0,0,0) and direction is (0,0,1)
     **/
    Ray();


    /**
     * @brief Ray
     * @param origin origin of the ray
     * @param direction direction of the ray
     **/
    Ray(const glm::vec3 origin, const glm::vec3 direction);


// Main methods
public:


    glm::vec3 getPointInRay(float t);

};


class hitable
{
public:


    /**
     * @brief hit hit result between a ray and an hittable object
     * @param ray incoming ray
     * @param distance_min minimal distance of the ray
     * @param distance_max maximal distance of the ray
     * @param htInfo information of the hit point if the ray hit an object
     * @return
     **/
    virtual bool hit(const Ray& ray, float distance_min, float distance_max, hitInfo& htInfo) const = 0;

};

#endif
