// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/renderer.h>
#include <common/sprite.h>
#include <common/print.h>

int main( void )
{
    Renderer renderer;
    Sprite* sprite1 = new Sprite();
    Sprite* sprite2 = new Sprite();
    
    do {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        sprite1->loadTexture("assets/test2.bmp");
        renderer.renderSprite(sprite1);
        sprite1->setRotationZ(90);
        sprite1->setPosX(300);
        sprite1->setScaleX(0.8f);
        sprite1->setScaleY(0.8f);
        
        sprite2->loadTexture("assets/test.bmp");
        renderer.renderSprite(sprite2);
        sprite2->setRotationZ(270);
        sprite2->setPosX(800);
        sprite2->setScaleX(0.8f);
        sprite2->setScaleY(0.8f);
        
        // Swap buffers
        glfwSwapBuffers(renderer.window());
        glfwPollEvents();
        
    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
          glfwWindowShouldClose(renderer.window()) == 0 );
    
    delete sprite1;
    delete sprite2;
    
    // Close OpenGL window and terminate GLFW
    glfwTerminate();
    
    return 0;
}