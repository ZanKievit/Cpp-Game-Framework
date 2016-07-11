// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/renderer.h>
#include <common/camera.h>
#include <common/scene.h>

#include <common/sprite.h>

#include "level1.h"
#include "level2.h"

int main( void )
{
	Renderer renderer;
	Level1* level1 = new Level1();
	Level2* level2 = new Level2();
	level1->setWindow(renderer.window());
	level2->setWindow(renderer.window());
	level1->run();
	level2->run();
	bool isRunning = true;
	
	do {
		if(level1->isRunning()){
			renderer.renderScene(level1);
			level1->Update();
		}else if(level2->isRunning()){
			renderer.renderScene(level2);
			level2->Update();
		}else{
			isRunning = false;
		}
	} // Check if the ESC key was pressed or the window was closed or is still running
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		  glfwWindowShouldClose(renderer.window()) == 0 && isRunning);
	
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	
	delete level1;
	
	return 0;
}
