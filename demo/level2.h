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
#include <common/print.h>

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
    Sprite* playerSprite = new Sprite(); ///< @brief The Sprite of the Player
    Sprite* groundSprite = new Sprite(); ///< @brief The Sprite of ground
    Player* _player = new Player(); ///< @brief The _player of Level2
    
    Gameobject* _ground = new Gameobject(); ///< @brief The _ground of Level2
    Gameobject* _ground2 = new Gameobject(); ///< @brief The _ground2 of Level2
    Gameobject* _ground3 = new Gameobject(); ///< @brief The _ground3 of Level2
    Gameobject* _ground4 = new Gameobject(); ///< @brief The _ground4 of Level2
    Gameobject* _ground5 = new Gameobject(); ///< @brief The _ground5 of Level2
    Gameobject* _ground6 = new Gameobject(); ///< @brief The _ground6 of Level2
    Gameobject* _ground7 = new Gameobject(); ///< @brief The _ground7 of Level2
    
    GLFWwindow* _window; ///< @brief The GLFWwindow of the Level2
};

#endif /* level2_h */
