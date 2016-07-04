#include "player.h"

Player::Player(){
    jump = false;
}

Player::~Player(){
    
}

void Player::move()
{
    float speed = 150.0f;
    float jumpForce = -3000;
    float gravity = 100;
    static double lastTime = glfwGetTime();
    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);
    glm::vec2 velocity = glm::vec2(0, 0);
    
    if (glfwGetKey( _window, GLFW_KEY_D ) == GLFW_PRESS){
        velocity.x = speed;
    }
    else if (glfwGetKey( _window, GLFW_KEY_A ) == GLFW_PRESS){
        velocity.x = -speed;
    }
    
    if (glfwGetKey(_window, GLFW_KEY_W ) == GLFW_RELEASE && !jump){
        jumpAmount = 0;
    }else if(glfwGetKey(_window, GLFW_KEY_W ) == GLFW_PRESS && isGrounded() && !jump && jumpAmount == 0){
        jump = true;
        jumpAmount++;
    }

    if(jump){
        velocity.y = jumpForce;
    }
    
    velocity.y += gravity;
    if(isGrounded()){
        velocity.y  -= gravity;
        jump = false;
    }
    this->posy += velocity.y * deltaTime;
    this->posx += velocity.x * deltaTime;
    lastTime = currentTime;
}