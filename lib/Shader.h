//**********************************************************************//
// Shader.h - The class that represents a shader code.			//
// 									//
//									//
// Autor: Luiz Augusto Volpi Nascimento.				//
// version: 0.1								//
// data: 17/06/2013							//
//									//
//**********************************************************************//

#ifndef _SHADER_H_
#define _SHADER_H_
//common libs
#include <string.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

//OpenGl libs
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
namespace sgl{
	
	class Shader{
		
		public:
			//enum ShaderType{GL_VERTEX_SHADER, GL_FRAGMENT_SHADER,GL_GEOMETRY_SHADER};
			bool loadShader(string file, int type); 
			void deleteShader(); 
			bool isLoaded(); 
		   	GLuint getShaderID(); 
		private:

			GLuint shaderID; // ID of shader
   			int shaderType; // GL_VERTEX_SHADER, GL_FRAGMENT_SHADER...
   			bool iLoaded; // Whether shader was loaded and compiled
	};
}
#endif
