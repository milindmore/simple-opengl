//**********************************************************************//
// OpenGLControl.h - The class that create and manage an environment	//
// to use OpenGL functions.						//
//									//
// Autor: Luiz Augusto Volpi Nascimento.				//
// version: 0.1								//
// data: 17/06/2013							//
//									//
//**********************************************************************//

#ifndef _OPENGLCONTROL_H_
#define _OPENGLCONTROL_H_

//Common includes
#include <stdio.h>
#include <string>
//OpenGL includes
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
using namespace glm;
using namespace std;
namespace sgl{
	
	class OpenGLControl{
		private:
		public:
			//Method that initialize the opengl resources.
			void initOpenGL(const char* title, int width, int height, int minorVersion, int majorVersion);
			//Method that is responsible to adjust the window when it is resized.
			void resizeWindow();
			//Method that clean the memory releasing the opengl resources.
			void releaseOpenglControl();


	};
}
#endif
