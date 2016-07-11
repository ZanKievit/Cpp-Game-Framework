/**
 * @file sprite.h
 *
 * @brief The Sprite header file.
 *
 * This file is part of Framework_Zan, a 2D OpenGL framework.
 *
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *   - Initial commit
 * - Copyright 2016 Zan Kievit <zan_kievit@live.nl>
 *   - Second commit
 */
#ifndef SPRITE_H
#define SPRITE_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>

#include <common/texture.h>

/// @brief The Sprite class defines the Texture, Shader, blend Color and pivot point of a Sprite.
class Sprite
{
public:
    Sprite(); ///< @brief Constructor of the Sprite
    virtual ~Sprite(); ///< @brief Destructor of the Sprite
    
    /// @brief setup the Sprite
    /// @param width The width of the Sprite
    /// @param height The height of the Sprite
    /// @param textureName The path to the texture of the Sprite
    void setSprite(int width, int height, std::string textureName);
    
    /// @brief get the width of this Sprite
    /// @return int _width
    int getWidth(){return _width;};
    /// @brief get the height of this Sprite
    /// @return int _height
    int getHeight(){return _height;};
    
    /// @brief get the texture
    /// @return GLuint _texture
    GLuint texture() { return _texture; };
    // @brief get the vertexbuffer
    /// @return GLuint _vertexbuffer
    GLuint vertexbuffer() { return _vertexbuffer; };
    // @brief get the uvbuffer
    /// @return GLuint _uvbuffer
    GLuint uvbuffer() { return _uvbuffer; };
    
private:
    int _width; ///< @brief the _width of Sprite
    int _height; ///< @brief the _height of Sprite
    
    GLuint _texture; ///< @brief the _texture of Sprite
    GLuint _vertexbuffer; ///< @brief the _vertexbuffer of Sprite
    GLuint _uvbuffer; ///< @brief the _uvbuffer of Sprite
};

#endif /* SPRITE_H */
