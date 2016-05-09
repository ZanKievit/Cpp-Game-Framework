#ifndef Gameobject_h
#define Gameobject_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

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
    
    float posx;
    float posy;
    float rotation;
    float scalex;
    float scaley;
    
    void addSprite(Sprite* spr);
    
    void addChild(Gameobject* child);
    void removeChild(Gameobject* child);
    
    Sprite* sprite() { return _sprite; };
    Gameobject* parent() { return _parent; };
    
    float worldPosX() { return _worldPosX; };
    float worldPosY() { return _worldPosY; };
    void setWorldPosX(float value){_worldPosX = value;};
    void setWorldPosY(float value){_worldPosY = value;};
    
private:
    Sprite* _sprite;
    Gameobject* _parent;
    
    float _worldPosX;
    float _worldPosY;
    
    void deleteSprite() {
        if (_sprite != NULL) {
            _sprite = new Sprite;
            delete _sprite;
            _sprite = NULL;
        }
    };
};

#endif /* Gameobject_h */
