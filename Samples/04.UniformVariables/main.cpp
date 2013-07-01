#include <iostream>
#include "../../lib/OpenGLControl.h"
#include "../../lib/Object.h"
#include"../../lib/Shader.h"
#include"../../lib/ShaderProgram.h"
using namespace sgl;
using namespace std;

int main(){
	OpenGLControl sglControl;
	sglControl.initOpenGL("04 - Uniform Variables",1024,768,3,3);
	
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

	GLuint gScaleLocation = glGetUniformLocation(shProg.getProgramID(),"gScale");
	cout<<gScaleLocation<<endl;
	do{
		glClear(GL_COLOR_BUFFER_BIT);

    		static float Scale = 0.0f;
		Scale+=0.001f;
    		
		glUniform1f(gScaleLocation,sinf(Scale));
		triangle.render(GL_TRIANGLES);
		glfwSwapBuffers();

   
	}while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
	glfwGetWindowParam( GLFW_OPENED ) );
	glDeleteVertexArrays(1, &VertexArrayID);
	glfwTerminate();
	return 0;

}
