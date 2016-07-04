/**
 * @file camera.h
 *
 * @brief The Camera header file.
 *
 * This file is part of Framework_Zan, a 2D OpenGL framework.
 *
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *   - Initial commit
 */
#ifndef CAMERA_H
#define CAMERA_H

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

/**
 * @brief The Camera class handles the concept of having a Camera in your Scene.
 */
class Camera
{
public:
    Camera(); ///< @brief Constructor of the Camera
    virtual ~Camera(); ///< @brief Destructor of the Camera
    
    void computeMatricesFromInputs(GLFWwindow* window);
    glm::mat4 getViewMatrix(){return ViewMatrix;}
    glm::mat4 getProjectionMatrix(){return ProjectionMatrix;}
    glm::vec3 getCursor(){return cursor;}
    
private:
    glm::mat4 ViewMatrix; ///< @brief The viewMatrix of the Camera
    glm::mat4 ProjectionMatrix; ///< @brief The (orthographic) projectionMatrix of the Camera
    
    glm::vec3 position; ///< @brief The position of the Camera
    glm::vec3 cursor; ///< @brief The cursor of the Camera
    
    float speed = 300.0f; // 300 units / second
};

#endif
