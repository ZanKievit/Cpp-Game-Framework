#include <common/renderer.h>

Renderer::Renderer()
{
    window_width = 1280;
    window_height = 720;
    
    fragment_shader	= "shaders/sprite.frag";
    vertex_shader	= "shaders/sprite.vert";
    
    this->init();
}

Renderer::~Renderer()
{
    // Cleanup VBO and shader
    glDeleteProgram(programID);
    glDeleteTextures(1, &textureID);
}

int Renderer::init()
{
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }
    
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    
    // Open a window and create its OpenGL context
    _window = glfwCreateWindow( window_width, window_height, "Demo", NULL, NULL);
    if( _window == NULL ){
        fprintf( stderr, "Failed to open GLFW window.\n" );
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(_window);
    
    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }
    
    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);
    
    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    
    // Enable depth test
    //glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    //glDepthFunc(GL_LESS);
    
    // Cull triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);
    
    // Create and compile our GLSL program from the shaders
    // see: shader.h/cpp
    programID = LoadShaders(vertex_shader.c_str(), fragment_shader.c_str());
    
    // Get a handle for our buffers
    vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
    vertexUVID = glGetAttribLocation(programID, "vertexUV");
    
    // Get a handle for our "MVP" uniform
    matrixID = glGetUniformLocation(programID, "MVP");
    // Get a handle for our "myTextureSampler" uniform
    textureID  = glGetUniformLocation(programID, "myTextureSampler");
    
    ProjectionMatrix = glm::ortho(0.0f, (float)window_width, (float)window_height, 0.0f, 0.1f, 100.0f);
    
    return 0;
}

void Renderer::renderScene(Scene* scene)
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _viewMatrix = scene->camera()->getViewMatrix();
    _projectionMatrix = scene->camera()->getProjectionMatrix();
    
    // 'root' scene node has identity Matrix
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    
    this->renderGameobject(modelMatrix, scene, scene->camera());
    
    // Swap buffers
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

void Renderer::renderGameobject(const glm::mat4& modelMatrix, Gameobject* gameobject, Camera* camera)
{
    glm::vec4 realpos = modelMatrix * glm::vec4(0,0,0,1);
    gameobject->setWorldPosX(realpos.x);
    gameobject->setWorldPosY(realpos.y);
    
    Sprite* sprite = gameobject->sprite();
    if (sprite != NULL) {
        renderSprite(modelMatrix, gameobject->sprite(), camera);
    }
    
    // Render all Children
    std::vector<Gameobject*> children = gameobject->children();
    for (int child = 0; child < children.capacity(); child++) {
        // Transform child's children...
        this->renderGameobject(_getModelMatrix(children.at(child)), children.at(child), camera);
    }
}

glm::mat4 Renderer::_getModelMatrix(Gameobject* gameobject)
{
    glm::vec3 position = glm::vec3(gameobject->posx, gameobject->posy, 0.0f);
    glm::vec3 rotation = glm::vec3(0.0f, 0.0f, gameobject->rotation);
    glm::vec3 scale = glm::vec3(gameobject->scalex, gameobject->scaley, 1.0f);
    
    // Build the Model matrix
    glm::mat4 translationMatrix	= glm::translate(glm::mat4(1.0f), position);
    glm::mat4 rotationMatrix	= glm::eulerAngleYXZ(0.0f, 0.0f, rotation.z / 360 * 6.28f);
    glm::mat4 scalingMatrix		= glm::scale(glm::mat4(1.0f), scale);
    
    glm::mat4 ModelMatrix = translationMatrix * rotationMatrix * scalingMatrix;
    
    return ModelMatrix;
}

void Renderer::renderSprite(const glm::mat4& modelMatrix, Sprite* sprite, Camera* camera)
{
    // Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
    camera->computeMatricesFromInputs(_window);
    
    //glm::vec3 cursor = getCursor();
    //printf("(%f,%f)\n",cursor.x, cursor.y);
    
    glm::mat4 ViewMatrix = camera->getViewMatrix(); // get from Camera (Camera position and direction)
    
    // Use our shader
    glUseProgram(programID);
    
    glm::mat4 MVP = ProjectionMatrix * ViewMatrix * modelMatrix;
    
    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
    
    // Bind our texture in Texture Unit 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, sprite->texture());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Set our "myTextureSampler" sampler to user Texture Unit 0
    glUniform1i(textureID, 0);
    
    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(vertexPosition_modelspaceID);
    glBindBuffer(GL_ARRAY_BUFFER, sprite->vertexbuffer());
    glVertexAttribPointer(
      vertexPosition_modelspaceID,  // The attribute we want to configure
      3,							// size : x+y+z => 3
      GL_FLOAT,                     // type
      GL_FALSE,                     // normalized?
      0,							// stride
      (void*)0                      // array buffer offset
      );
    
    // 2nd attribute buffer : UVs
    glEnableVertexAttribArray(vertexUVID);
    glBindBuffer(GL_ARRAY_BUFFER, sprite->uvbuffer());
    glVertexAttribPointer(
      vertexUVID,                   // The attribute we want to configure
      2,                            // size : U+V => 2
      GL_FLOAT,                     // type
      GL_FALSE,                     // normalized?
      0,							// stride
      (void*)0                      // array buffer offset
      );
    
    // Draw the triangles !
    glDrawArrays(GL_TRIANGLES, 0, 2*3); // 2*3 indices starting at 0 -> 2 triangles
    
    glDisableVertexAttribArray(vertexPosition_modelspaceID);
    glDisableVertexAttribArray(vertexUVID);
}

