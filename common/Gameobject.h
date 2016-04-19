#ifndef Gameobject_h
#define Gameobject_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <common/sprite.h>

class Gameobject
{
public:
    Gameobject();
    virtual ~Gameobject();
    
    float positionx;
    float positiony;
    float rotation;
    float scalex;
    float scaley;
    
    Sprite* sprite() { return _sprite; };
    
    void addSprite(Sprite* spr);
    
private:
    
    Sprite* _sprite;
    
    void deleteSprite() {
        if (_sprite != NULL) {
            _sprite = new Sprite;
            delete _sprite;
            _sprite = NULL;
        }
    };
};

#endif /* Gameobject_h */
