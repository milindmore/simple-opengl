#include "../lib/OpenGLControl.h"

void sgl::OpenGLControl::initOpenGL(const char* title, int width, int height, int minorVersion, int majorVersion){
	if( !glfwInit() ){
    		fprintf( stderr, "Error: Failed to initialize GLFW\n" );
    		exit(-1);
	}
	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4); // 4x antialiasing
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, majorVersion); // We want OpenGL 3.3
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, minorVersion);
	if(majorVersion > 2)
		glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL
	 
	// Open a window and create its OpenGL context
	if( !glfwOpenWindow( 1024, 768, 0,0,0,0, 32,0, GLFW_WINDOW ) )
	{
	    fprintf( stderr, "Error: Failed to open GLFW window\n" );
	    glfwTerminate();
	    exit(-1);
	}
	 
	// Initialize GLEW
	glewExperimental=true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
	    fprintf(stderr, "Error: Failed to initialize GLEW\n");
	    exit(-1);
	}
	 
	glfwSetWindowTitle( title );

}
