//**********************************************************************//
// Object.h - The class that represents a object that will be present	//
// and rendered in the scene.						//
//									//
// Autor: Luiz Augusto Volpi Nascimento.				//
// version: 0.1								//
// data: 17/06/2013							//
//									//
//**********************************************************************//


#ifndef _OBJECT_H_
#define _OBJECT_H_
//common libs
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

//opengl libs
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

namespace sgl{
	class Object{
		private:
			//vertexBuffer idexer
			GLuint vertexBuffer;
			//colorBuffer indexer
			GLuint colorBuffer;
			// vector that contain the color RGB of each vertex of the object
			std::vector<glm::vec3> color;
			// vector that contain the position of each vertex of the object
			std::vector<glm::vec3> vertices;
			bool hasColor;
			
		public:
			//Simple Contructor
			Object();

			//contructor that create a object from a vector of vertex
			Object(std::vector<glm::vec3> vertices);
	
			~Object();

			//define the set of vertex of the object
			void setVertices(std::vector<glm::vec3> vertices);

			//define de set of vertex color of the object
			void setColor(std::vector<glm::vec3> color);
			//render the object on the window
			void render(GLenum mode);
			
	};
}
#endif
