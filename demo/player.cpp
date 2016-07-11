#include "player.h"

Player::Player(){
    jump = false;
    velocity = glm::vec2(0, 0);
    maxVelocity = glm::vec2(300, 0);
}

Player::~Player(){
    
}


void Player::move()
{
    float speed = 30.0f;
    float jumpForce = -900;
    float gravity = 30;
    static double lastTime = glfwGetTime();
    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);
    
    if (glfwGetKey( _window, GLFW_KEY_D ) == GLFW_PRESS && !_isLeftsideCol){
        velocity.x += speed;
    }
    else if (glfwGetKey( _window, GLFW_KEY_A ) == GLFW_PRESS && !_isRightsideCol){
        velocity.x -= speed;
    }
    else
    {
        if(velocity.x > 0.1){
            velocity.x -= (speed/2);
        }else if(velocity.x < -0.1){
            velocity.x += (speed/2);
        }
    }
    
    if (glfwGetKey(_window, GLFW_KEY_W ) == GLFW_RELEASE && !jump && _isGrounded){
        jumpAmount = 0;
    }else if(glfwGetKey(_window, GLFW_KEY_W ) == GLFW_PRESS && !jump && jumpAmount == 0){
        jump = true;
        jumpAmount++;
    }
    
    if(_isGrounded){
        velocity.y = 0;
        if(jump){
            velocity.y = jumpForce;
            jump = false;
        }
    }else{
        velocity.y += gravity;
    }
    
    if(_isLeftsideCol){
        if(velocity.x > 0.1f){
            velocity.x = 0;
        }
    }
    if(_isRightsideCol){
        if(velocity.x < 0.1f){
            velocity.x = 0;
        }
    }
    
    if(velocity.x > maxVelocity.x){velocity.x = maxVelocity.x;}
    if(velocity.x < -maxVelocity.x){velocity.x = -maxVelocity.x;}
    
    this->posy += velocity.y * deltaTime;
    this->posx += velocity.x * deltaTime;
    lastTime = currentTime;
}