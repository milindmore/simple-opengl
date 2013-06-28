#include <iostream>
#include "../../lib/OpenGLControl.h"

using namespace std;

int main(){
	sgl::OpenGLControl sglControl;
	sglControl.initOpenGL("My first Window",1024,768,3,3);
	// Ensure we can capture the escape key being pressed below
	glfwEnable( GLFW_STICKY_KEYS );
	 
	do{
	   
	    glfwSwapBuffers();
	 
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
	glfwGetWindowParam( GLFW_OPENED ) );
	
}
