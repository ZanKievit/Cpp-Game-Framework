/**
 * @file shader.h
 *
 * @brief The Shader header file.
 *
 * This file is part of Framework_Zan, a 2D OpenGL framework.
 *
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *   - Initial commit
 */
#ifndef SHADER_H
#define SHADER_H

/// @brief load shaders from disk
/// @param vertex_file_path path to vertexshader
/// @param fragment_file_path path to fragmentshader
/// @return GLuint _programID
GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);

#endif
