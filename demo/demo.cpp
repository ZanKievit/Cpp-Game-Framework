// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/renderer.h>
#include <common/gameobject.h>
#include <common/print.h>

int main( void )
{
    Renderer renderer;
    Sprite* sprite1 = new Sprite();
    Gameobject* object1 = new Gameobject();
    
    do {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        sprite1->loadTexture("assets/test.bmp");
        renderer.renderSprite(sprite1);
        object1->addSprite(sprite1);
        renderer.renderGameobject(object1);
        
        // Swap buffers
        glfwSwapBuffers(renderer.window());
        glfwPollEvents();
        
    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
          glfwWindowShouldClose(renderer.window()) == 0 );
    
    // Close OpenGL window and terminate GLFW
    glfwTerminate();
    
    return 0;
}