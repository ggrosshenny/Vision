#include "Ray.h"


Ray::Ray()
{
    this->origin = glm::vec3(0.0f, 0.0f, 0.0f);
    this->direction = glm::vec3(0.0f, 0.0f, -1.0f);
}


Ray::Ray(const glm::vec3 origin, const glm::vec3 direction)
{
    this->origin = origin;
    this->direction = direction;
}

glm::vec3 Ray::getPointInRay(float t)
{
    return origin + t * direction;
}

