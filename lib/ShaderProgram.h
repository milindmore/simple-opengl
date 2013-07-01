//**********************************************************************//
// ShaderProgram.h - The class that represents a shader program.	//
// 									//
//									//
// Autor: Luiz Augusto Volpi Nascimento.				//
// version: 0.1								//
// data: 17/06/2013							//
//									//
//**********************************************************************//


#ifndef _SHADERPROGRAM_H_
#define _SHADERPROGRAM_H_

//OpenGL libs
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
//vriGL libs
#include "Shader.h"
namespace sgl{
	
		
	class ShaderProgram { 
		private: 
		   GLuint programID; // ID of program
		   bool bLinked; // Whether program was linked and is ready to use
		public: 
		   void createProgram(); 
		   void deleteProgram(); 

		   bool addShaderToProgram(Shader* shShader); 
		   bool linkProgram(); 

		   void useProgram(); 

		   GLuint getProgramID(); 

		   ShaderProgram(); 

		
	};
}
#endif
