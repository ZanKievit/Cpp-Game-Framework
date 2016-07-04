/**
 * @file renderer.h
 *
 * @brief The Renderer header file.
 *
 * This file is part of Framework_Zan, a 2D OpenGL framework.
 *
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *   - Initial commit
 * - Copyright 2016 Zan Kievit <zan_kievit@live.nl>
 *   - Second commit
 */

#ifndef RENDERER_H
#define RENDERER_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <common/shader.h>
#include <common/sprite.h>
#include <common/texture.h>
#include <common/camera.h>
#include <common/scene.h>
#include <common/print.h>

/// @brief The Renderer class renders meshes (vertices, normals, UV coordinates) from Sprites.
class Renderer
{
public:
    Renderer(); ///< @brief Constructor of the Renderer
    virtual ~Renderer(); ///< @brief Destructor of the Renderer
    
    /// @brief access the GLFWwindow.
    /// @return GLFWwindow* _window
    GLFWwindow* window() { return _window; };
    
    /// @brief Renders a Scene with all its children.
    /// @param scene The Scene that needs to be rendered
    /// @return void
    void renderScene(Scene* scene);
    
private:
    /// @brief Initialise the Renderer. Create a Window with OpenGL Context.
    /// @return int (0 when successful, -1 when errors occurred)
    int init();
    
    /// @brief Recursive function that renders an Entity which is a child of the Scene or parent Entity.
    /// @param modelMatrix The modelMatrix of the parent
    /// @param gameobject The Gameobject that needs rendering
    /// @param camera The camera in case we need to cull Sprites
    /// @return void
    void renderGameobject(const glm::mat4& modelMatrix, Gameobject* gameobject, Camera* camera);
    
    /// @brief Renders the Sprite 'component' of a Gameobject.
    /// @param modelMatrix The ModelMatrix of the Gameobject
    /// @param sprite The Sprite 'component' of the Gameobject
    /// @param camera The camera we need to cull Sprites
    /// @return void
    void renderSprite(const glm::mat4& modelMatrix, Sprite* sprite, Camera* camera);
    
    /// @brief get the modelMatrix from a Gameobject.
    /// @param gameobject The Gameobject we need the modelMatrix from.
    /// @return glm::mat4
    glm::mat4 _getModelMatrix(Gameobject* gameobject);
        
    GLFWwindow* _window; ///< @brief The GLFWwindow of the Renderer
    int window_width; ///< @brief The width of _window
    int window_height; ///< @brief The height of _window
        
    std::string fragment_shader; ///< @brief The path to a shader of Shader
    std::string vertex_shader; ///< @brief The path to a shader of Shader
        
    GLuint programID; ///< @brief programID (pointer to compiled shader)
    GLuint vertexPosition_modelspaceID;
    GLuint vertexUVID;
    GLuint matrixID; ///< @brief attaches to MVP uniform in shader
    GLuint textureID; ///< @brief attaches to textureSampler uniform in shader
    
    // temp 'local' variables.
    glm::mat4 ProjectionMatrix; ///< @brief The ProjectionMatrix we get from the GLFWwindow.
    glm::mat4 _projectionMatrix; ///< @brief The _projectionMatrix we get from the Camera. We only get the ProjectionMatrix from the orthographic camera once
    glm::mat4 _viewMatrix; ///< @brief The _viewMatrix we get from the Camera once per frame.
};

#endif /* RENDERER_H */

