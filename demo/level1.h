/**
 * @file level1.h
 *
 * @brief The Level1 header file.
 *
 * This file is part of demo, a gsme to test Framework_Zan.
 *
 * - Copyright 2016 Zan Kievit <zan_kievit@live.nl>
 */
#ifndef level1_h
#define level1_h

#include <stdio.h>

#include <common/scene.h>
#include "player.h"

/// @brief The Level1 class is a Scene that contains objects.
class Level1: public Scene
{
public:
    Level1(); ///< @brief Constructor of the Level1
    virtual ~Level1(); ///< @brief Destructor of the Level1
    
    virtual void Update();
    
    /// @brief sets the GLFWwindow of Level1.
    /// @param window The new GLFWwindow of window
    void setWindow(GLFWwindow* window){_window = window;}
    
protected:
    
private:
    Sprite* playerSprite = new Sprite(); ///< @brief The Sprite of the Player
    Sprite* groundSprite = new Sprite(); ///< @brief The Sprite of ground
    Sprite* spikeSprite = new Sprite(); ///< @brief The Sprite of spikes
    Sprite* endSprite = new Sprite(); ///< @brief The Sprite of the end
    Player* _player = new Player(); ///< @brief The _player of Level1
    
    Gameobject* _ground = new Gameobject(); ///< @brief The _ground of Level1
    Gameobject* _ground2 = new Gameobject(); ///< @brief The _ground2 of Level1
    Gameobject* _ground3 = new Gameobject(); ///< @brief The _ground3 of Level1
    Gameobject* _ground4 = new Gameobject(); ///< @brief The _ground4 of Level1
    Gameobject* _ground5 = new Gameobject(); ///< @brief The _ground5 of Level1
    Gameobject* _ground6 = new Gameobject(); ///< @brief The _ground6 of Level1
    Gameobject* _ground7 = new Gameobject(); ///< @brief The _ground7 of Level1
    Gameobject* _ground8 = new Gameobject(); ///< @brief The _ground8 of Level1
    
    Gameobject* _spike1 = new Gameobject(); ///< @brief The _spike1 of Level1
    Gameobject* _spike2 = new Gameobject(); ///< @brief The _spike2 of Level1
    
    Gameobject* end = new Gameobject(); ///< @brief The end of Level1
    
    GLFWwindow* _window; ///< @brief The GLFWwindow of Level1
    
    void start();
    void reset();
};

#endif /* level1_h */
