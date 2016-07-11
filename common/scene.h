/**
 * @file scene.h
 *
 * @brief The Scene header file.
 *
 * This file is part of Framework_Zan, a 2D OpenGL framework.
 *
 * - Copyright 2016 Zan Kievit <zan_kievit@live.nl>
 */
#ifndef scene_h
#define scene_h

#include <stdio.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <common/camera.h>
#include <common/gameobject.h>

/// @brief The Scene class is the Base class for your own Scenes. It has a Camera and a basic on/off state machine.
class Scene: public Gameobject
{
public:
    Scene(); ///< @brief Constructor of the Scene
    virtual ~Scene(); ///< @brief Destructor of the Scene
    
    /// @brief whether this Scene is running or not.
    /// @return bool _isRunning
    bool isRunning(){return _isRunning;}
    /// @brief get a pointer to the Camera
    /// @return Texture* a pointer to the Camera
    Camera* camera(){return _camera;}
    
    /// @brief start running the Scene
    /// @return void
    void run(){_isRunning = true;}
    /// @brief stop running the Scene
    /// @return void
    void stopRunning(){_isRunning = false;}
    
private:
    Camera* _camera; ///< @brief the Camera instance
    
    bool _isRunning = false; ///< @brief is running or not
};
#endif /* Scene_h */
