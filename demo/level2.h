/**
 * @file level2.h
 *
 * @brief The Level2 header file.
 *
 * This file is part of demo, a gsme to test Framework_Zan.
 *
 * - Copyright 2016 Zan Kievit <zan_kievit@live.nl>
 */
#ifndef level2_h
#define level2_h

#include <stdio.h>

#include <common/scene.h>
#include "player.h"

/// @brief The Level2 class is a Scene that contains objects.
class Level2: public Scene
{
public:
    Level2(); ///< @brief Constructor of the Level2
    virtual ~Level2(); ///< @brief Destructor of the Level2
    
    virtual void Update();
    
    /// @brief sets the GLFWwindow of Level2.
    /// @param window The new GLFWwindow of window
    void setWindow(GLFWwindow* window){_window = window;}
    
protected:
    
private:
    Sprite* playerSprite; ///< @brief The Sprite of the Player
    Sprite* groundSprite; ///< @brief The Sprite of ground
    Player* _player; ///< @brief The _player of Level2
    
    Gameobject* _ground; ///< @brief The _ground of Level2
    Gameobject* _ground2; ///< @brief The _ground2 of Level2
    Gameobject* _ground3; ///< @brief The _ground3 of Level2
    Gameobject* _ground4; ///< @brief The _ground4 of Level2
    Gameobject* _ground5; ///< @brief The _ground5 of Level2
    Gameobject* _ground6; ///< @brief The _ground6 of Level2
    Gameobject* _ground7; ///< @brief The _ground7 of Level2
    
    GLFWwindow* _window; ///< @brief The GLFWwindow of the Level2
};

#endif /* level2_h */
