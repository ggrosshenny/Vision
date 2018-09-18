#ifndef __MODEL3D_H
#define __MODEL3D_H

#include "Mesh.h"
// Standard library
#include <map>
// SOIL
#include <SOIL/SOIL.h>


struct classComp
{
    bool operator() (const std::string& path1, const std::string& path2) const
    { return path1<path2; }
};


class Model3D
{
// Attributes
private:
    /// List of meshes
    std::vector<Mesh> meshes;
    /// Texture directory
    std::string directory;
    /// Loaded textures
    std::map<std::string, Texture, classComp> loadedTextures;
    // Used to not overflow the cerr output
    bool WarningMessageForShaderAlreadyShown;
    /// local transformation matrix
    glm::mat4 localTransformationMatrix;



// Constructor
public:


    /**
     * @brief Model3D Constructor of the Model3D object
     * @param path path of the 3D model
     */
    Model3D();


// Getters and setters
public:


    /**
     * @brief getLocalTransformationMatrix return the local transformation matrix of the model
     * @return
     */
    glm::mat4 getLocalTransformationMatrix();


    /**
     * @brief setLocalTransformationMatrix change the local transformation matrix of the model with the given one
     * @param matrix
     */
    void setLocalTransformationMatrix(glm::mat4 matrix);


    /**
     * @brief setLocalTransformationMatrix create the new transformation matrix of the mode with the given vectors
     * @param scaleVector scale vector to add to the matrix
     * @param rotateVector rotation vector to add to the matrix
     * @param translateVector translation vector to add to the matrix
     */
    void setLocalTransformationMatrix(glm::vec3 scaleVector, float rotationAngle, glm::vec3 rotateVector, glm::vec3 translateVector);

    /**
     * @brief transformLocalMatrix multiply the local transformation matrix of the 3D model with matrix
     * @param matrix transformation to be applied to the 3D model's matrix
     */
    void transformLocalMatrix(glm::mat4 matrix);

// Methods
public:


    /**
     * @brief draw draw all meshes of the 3D model with the given shader object
     * @param shader
     */
    void draw(Shader& shader);


    /**
     * @brief draw draw all meshes of the 3D model with the given shader object and the given skybox texture
     * @param shader
     */
    void draw(Shader& shader, GLuint skyboxTextureID);


    /**
     * @brief textureFromFile load and link to OpenGL a texture from a file
     * @param path file path
     * @param directory file directory
     * @return
     */
    static unsigned int textureFromFile(const std::string path, const std::string &directory);


};


#endif
