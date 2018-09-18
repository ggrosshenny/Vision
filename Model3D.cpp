#include "Model3D.h"


// ===========
// Constructor

Model3D::Model3D()
{
    this->WarningMessageForShaderAlreadyShown = false;
    this->localTransformationMatrix = glm::mat4(1.0f);
}


// ===================
// Getters and setters

glm::mat4 Model3D::getLocalTransformationMatrix()
{
    return this->localTransformationMatrix;
}

void Model3D::setLocalTransformationMatrix(glm::mat4 matrix)
{
    this->localTransformationMatrix = matrix;
}

void Model3D::setLocalTransformationMatrix(glm::vec3 scaleVector, float rotationAngle, glm::vec3 rotateVector, glm::vec3 translateVector)
{
    this->localTransformationMatrix = glm::mat4(1.0f);
    this->localTransformationMatrix = glm::scale(this->localTransformationMatrix, scaleVector);
    this->localTransformationMatrix = glm::rotate(this->localTransformationMatrix, rotationAngle, rotateVector);
    this->localTransformationMatrix = glm::translate(this->localTransformationMatrix, translateVector);
}

void Model3D::transformLocalMatrix(glm::mat4 matrix){
    this->localTransformationMatrix = matrix * this->localTransformationMatrix;
}

// =======
// Methods


void Model3D::draw(Shader &shader)
{
    for(unsigned int i = 0; i<this->meshes.size(); i++)
    {
        this->WarningMessageForShaderAlreadyShown = this->meshes[i].draw(shader, this->WarningMessageForShaderAlreadyShown);
    }
}

void Model3D::draw(Shader& shader, GLuint skyboxTextureID)
{
    for(unsigned int i = 0; i<this->meshes.size(); i++)
    {
        this->WarningMessageForShaderAlreadyShown = this->meshes[i].draw(shader, skyboxTextureID, this->WarningMessageForShaderAlreadyShown);
    }
}


unsigned int Model3D::textureFromFile(const std::string path, const std::string &directory)
{
    // Get full path of the texture
    std::string fileName = std::string(path);
    fileName = directory + '/' + fileName;
    //std::cout << "textureFromFile : " << fileName << std::endl;
    // Texture ID in OpenGL environment
    GLuint textureID;
    // Texture's data
    int width = 0;
    int height = 0;
    unsigned char* textureData;


    // Generate the texture in OpenGL
    glGenTextures(1, &textureID);

    // Retrieve texture data
    textureData = SOIL_load_image(fileName.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
    //std::cerr << "SOIL_LOADING error : " << SOIL_last_result() << std::endl;

    if(textureData != NULL)
    {
        // Bind the texture in OpenGL
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
        glGenerateMipmap(GL_TEXTURE_2D);

        // Set texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    else
    {
        std::cerr << "[WARNING] in Model3D, could not load texture at path : " << fileName.c_str() << std::endl;

    }

    SOIL_free_image_data(textureData);

    return textureID;
}


