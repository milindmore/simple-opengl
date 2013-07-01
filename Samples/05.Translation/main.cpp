#include <iostream>
#include "../../lib/OpenGLControl.h"
#include "../../lib/Object.h"
#include"../../lib/Shader.h"
#include"../../lib/ShaderProgram.h"
using namespace sgl;
using namespace std;

int main(){
	OpenGLControl sglControl;
	sglControl.initOpenGL("05 - Transformations",1024,768,3,3);
	
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);	

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//triangle triangleVertices
	vector<glm::vec3> triangleVertices;
	
	triangleVertices.push_back(glm::vec3(-0.1f,-0.1f,0.0f));
	triangleVertices.push_back(glm::vec3(0.1f,-0.1f,0.0f));
	triangleVertices.push_back(glm::vec3(0.0f,0.1f,0.0f));
	
	Object triangle(triangleVertices);

	vector<glm::vec3> squareVertices;

	squareVertices.push_back(glm::vec3(-0.1f,-0.2f,0.0f));
	squareVertices.push_back(glm::vec3(-0.1f,-0.4f,0.0f));
	squareVertices.push_back(glm::vec3(0.1f,-0.4f,0.0f));
	squareVertices.push_back(glm::vec3(-0.1f,-0.2f,0.0f));
	squareVertices.push_back(glm::vec3(0.1f,-0.2f,0.0f));
	squareVertices.push_back(glm::vec3(0.1f,-0.4f,0.0f));
	
	Object square(squareVertices);
	
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

	GLuint transformations = glGetUniformLocation(shProg.getProgramID(),"transformations");
	//cout<<gScaleLocation<<endl;
	do{
		glClear(GL_COLOR_BUFFER_BIT);

    		static float Scale = 0.0f;
		
    		Scale += 0.001f;
		triangle.translate(glm::vec3(sinf(Scale),0.0f,0.0f));
		glUniformMatrix4fv(transformations, 1, GL_TRUE, &(triangle.getTransformationsMatrix()[0][0]));
		triangle.render(GL_TRIANGLES);
		square.translate(glm::vec3(0.0f,sinf(Scale),0.0f));
		glUniformMatrix4fv(transformations, 1, GL_TRUE, &(square.getTransformationsMatrix()[0][0]));
		square.render(GL_TRIANGLES);
		
		glfwSwapBuffers();

   
	}while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
	glfwGetWindowParam( GLFW_OPENED ) );
	glDeleteVertexArrays(1, &VertexArrayID);
	glfwTerminate();
	return 0;

}
