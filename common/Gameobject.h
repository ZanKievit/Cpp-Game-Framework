/**
 * @file gameobject.h
 *
 * @brief The Gameobject header file.
 *
 * This file is part of Framework_Zan, a 2D OpenGL framework.
 *
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *   - Initial commit
 * - Copyright 2016 Zan Kievit <zan_kievit@live.nl>
 *   - Second commit
 */

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

/// @brief The Gameobject class is the Base class for the elements in your Scene.
class Gameobject
{
public:
    Gameobject(); ///< @brief Constructor of a Gameobject
    virtual ~Gameobject(); ///< @brief Destructor of a Gameobject
    
    // transform
    float posx; ///< @brief The x position of the Gameobject
    float posy; ///< @brief The y position of the Gameobject
    float rotation; ///< @brief The rotation of the Gameobject
    float scalex; ///< @brief The x scale of the Gameobject
    float scaley; ///< @brief The y scale of the Gameobject
    
    // data structure
    /// @brief add a Gameobject as a child of this Gameobject.
    /// Defines the data structure (parent/children relationship)
    /// @param child The Gameobject you want to add as a child.
    /// @return void
    void addChild(Gameobject* child);
    /// @brief remove this Gameobject from list of children.
    /// @param child The Gameobject you want to remove from your children.
    /// @return void
    void removeChild(Gameobject* child);
    /// @brief get the Gameobject from list of children.
    /// @param i The id of the Gameobject you want to get.
    /// @return Gameobject* child
    Gameobject* getChild(unsigned int i);
    /// @brief get the list of children.
    /// @return std::vector<Gameobject*>& _children
    std::vector<Gameobject*> children() { return _children; };
    
    // sprite
    /// @brief get the Sprite from this Gameobject.
    /// @return Sprite* _sprite
    Sprite* sprite() { return _sprite; };
    /// @brief add a Sprite to this Gameobject by Sprite*.
    /// @param spr A pointer to a Sprite.
    /// @return void
    void addSprite(Sprite* spr);

    /// @brief get the guid of this Gameobject.
    /// @return int _guid
    int guid() { return _guid; };
    /// @brief get the parent of this Gameobject.
    /// @return Gameobject* _parent
    Gameobject* parent() { return _parent; };
    
    /// @brief get the x world position of this Gameobject.
    /// @return float _worldPosX
    float worldPosX() { return _worldPosX; };
    /// @brief get the y world position of this Gameobject.
    /// @return float _worldPosY
    float worldPosY() { return _worldPosY; };
    
    /// @brief set the x world position of this Gameobject.
    /// @param value The new value of _worldPosX
    void setWorldPosX(float value){_worldPosX = value;};
    /// @brief set the y world position of this Gameobject.
    /// @param value The new value of _worldPosY
    void setWorldPosY(float value){_worldPosY = value;};
    
    /// @brief check if this Gameobject is colliding with object.
    /// @param object The Gameobject you want to check collision with
    bool IsCollidingWith(Gameobject* object);
    
private:
    // identity
    int _guid; ///< @brief The _guid of this Entity
    static int _nextGuid; ///< @brief The _nextGuid of this Entity
    
    Gameobject* _parent; ///< @brief The _parent of this Gameobject
    std::vector<Gameobject*> _children; ///< @brief The _children of this Gameobject
    
    Sprite* _sprite; ///< @brief The _sprite of this Gameobject
    
    float _worldPosX; ///< @brief The x position of the Gameobject in the real world
    float _worldPosY; ///< @brief The x position of the Gameobject in the real world
    
    /// @brief delete the Sprite of this Gameobject.
    /// @return void
    void deleteSprite() {
        if (_sprite != NULL) {
            _sprite = new Sprite();
            delete _sprite;
            _sprite = NULL;
        }
    };
};

#endif /* Gameobject_h */