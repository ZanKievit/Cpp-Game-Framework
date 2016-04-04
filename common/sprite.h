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
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <common/texture.h>

class Sprite
{
public:
    Sprite();
    virtual ~Sprite();
    
    void loadTexture(std::string textureName) {_texture = loadBMP_custom(textureName.c_str());};
    
    GLuint texture() { return _texture; };
    GLuint vertexbuffer() { return _vertexbuffer; };
    GLuint uvbuffer() { return _uvbuffer; };
    
    float getPosX() { return position_x; };
    float getPosY() { return position_y; };
    float getRotationZ() { return rotation_z; };
    
    void setPosX(float posX){ position_x = posX; };
    void setPosY(float posY){ position_y = posY; };
    
    void setRotationZ(float rotZ){ rotation_z = rotZ; };
    
    float getScaleX() { return scale_x; };
    float getScaleY() { return scale_y; };
    void setScaleX(float sclX){ scale_x = sclX; };
    void setScaleY(float sclY){ scale_y = sclY; };
    
private:
    GLuint _texture;
    GLuint _vertexbuffer;
    GLuint _uvbuffer;
    
    float position_x;
    float position_y;
    float rotation_z;
    float scale_x;
    float scale_y;
};

#endif /* SPRITE_H */
