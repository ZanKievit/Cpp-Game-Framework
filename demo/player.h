/**
 * @file player.h
 *
 * @brief The Player header file.
 *
 * This file is part of demo, a gsme to test Framework_Zan.
 *
 * - Copyright 2016 Zan Kievit <zan_kievit@live.nl>
 */
#ifndef Player_h
#define Player_h

#include <stdio.h>

#include <common/renderer.h>
#include <common/gameobject.h>

/// @brief The Player class is a Gameobject that is controllable and can be grounded.
class Player: public Gameobject
{
public:
    Player(); ///< @brief Constructor of the Player
    virtual ~Player(); ///< @brief Destructor of the Player
    
    /// @brief moves the Player.
    void move();
    /// @brief checks if Player _isGrounded.
    /// @return _isGrounded
    bool isGrounded(){return _isGrounded;}
    
    /// @brief set _isGrounded true.
    void isOnGround(){_isGrounded = true;}
    /// @brief set _isGrounded false.
    void isOffGround(){_isGrounded = false;}
    
    /// @brief sets the GLFWwindow of Player.
    /// @param window The new GLFWwindow of window
    void setWindow(GLFWwindow* window){_window = window;}
    
private:
    bool _isGrounded; ///< @brief The _isGrounded of the Player
    bool jump; ///< @brief The jump of the Player
    int jumpAmount; ///< @brief The jumpAmount of the Player
    
    GLFWwindow* _window; ///< @brief The GLFWwindow of the Player
};

#endif /* player_h */
