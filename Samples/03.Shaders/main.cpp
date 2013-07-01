#include "../../lib/OpenGLControl.h"
#include "../../lib/Object.h"
#include"../../lib/Shader.h"
#include"../../lib/ShaderProgram.h"
#include <iostream>
using namespace std;
using namespace sgl;

int main(){
	OpenGLControl sglControl;
	sglControl.initOpenGL("03 - Shaders",1024,768,3,3);
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//triangle triangleVertices
	vector<glm::vec3> triangleVertices;
	
	triangleVertices.push_back(glm::vec3(-0.1f,-0.1f,0.0f));
	triangleVertices.push_back(glm::vec3(0.1f,-0.1f,0.0f));
	triangleVertices.push_back(glm::vec3(0.0f,0.1f,0.0f));
	

	//triangle color
	vector<glm::vec3> triangleColor;
	
	triangleColor.push_back(glm::vec3(1.0f,0.0f,0.0f));
	triangleColor.push_back(glm::vec3(0.0f,1.0f,0.0f));
	triangleColor.push_back(glm::vec3(0.0f,0.0f,1.0f));
	
	Object triangle(triangleVertices);
	triangle.setColor(triangleColor);
	//square vertex
	vector<glm::vec3> squareVertices;

	squareVertices.push_back(glm::vec3(-0.1f,-0.2f,0.0f));
	squareVertices.push_back(glm::vec3(-0.1f,-0.4f,0.0f));
	squareVertices.push_back(glm::vec3(0.1f,-0.4f,0.0f));
	squareVertices.push_back(glm::vec3(-0.1f,-0.2f,0.0f));
	squareVertices.push_back(glm::vec3(0.1f,-0.2f,0.0f));
	squareVertices.push_back(glm::vec3(0.1f,-0.4f,0.0f));
	
	//square color

	vector<glm::vec3> squareColor;

	squareColor.push_back(glm::vec3(1.0f,0.0f,0.0f));
	squareColor.push_back(glm::vec3(1.0f,0.0f,0.0f));
	squareColor.push_back(glm::vec3(1.0f,0.0f,0.0f));
	squareColor.push_back(glm::vec3(1.0f,0.0f,0.0f));
	squareColor.push_back(glm::vec3(1.0f,0.0f,0.0f));
	squareColor.push_back(glm::vec3(1.0f,0.0f,0.0f));


	

	Object square(squareVertices);
	square.setColor(squareColor);
	
	//dot vertex
	vector<glm::vec3> dotVertex;
	dotVertex.push_back(glm::vec3(0.3f,0.3f,0.0f));
	//dot color
	vector<glm::vec3> dotColor;
	dotColor.push_back(glm::vec3(1.0f,1.0f,0.0f));	
	
	Object dot(dotVertex);
	dot.setColor(dotColor);

	//load shaders from file	
	Shader shVertex;
	shVertex.loadShader("data/vertexshader.glsl",GL_VERTEX_SHADER);
	Shader shFrag;
	shFrag.loadShader("data/fragmentshader.glsl",GL_FRAGMENT_SHADER);
	//create a chader program
	ShaderProgram shProg;
	shProg.createProgram();
	//add the shader on the program
	if(shProg.addShaderToProgram(&shVertex))
		cout<<"shader added sucessfully."<<endl;
	else
		cout<<"Failed to add the shader."<<endl;
	if(shProg.addShaderToProgram(&shFrag))
		cout<<"shader added sucessfully."<<endl;
	else
		cout<<"Failed to add the shader."<<endl;
	//link the program and use it
	shProg.linkProgram();
	shProg.useProgram();

	//render the objects
	do{
		glClear(GL_COLOR_BUFFER_BIT); 
		triangle.render(GL_TRIANGLES);
		square.render(GL_TRIANGLES);
		dot.render(GL_POINTS);
	    	glfwSwapBuffers();
	 
	}
	while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
	glfwGetWindowParam( GLFW_OPENED ) );
	glDeleteVertexArrays(1, &VertexArrayID);
	glfwTerminate();
	return 0;
	
}
