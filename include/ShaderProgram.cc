#include "../lib/ShaderProgram.h"

sgl::ShaderProgram::ShaderProgram(){
	this->bLinked = false;
}

void sgl::ShaderProgram::createProgram(){
	this->programID = glCreateProgram();
}

bool sgl::ShaderProgram::addShaderToProgram(Shader *shShader){
	if(!shShader->isLoaded())
		return false;

	glAttachShader(programID, shShader->getShaderID());
	
	return true;
}

bool sgl::ShaderProgram::linkProgram(){
	
	int iLinkStatus;	
	
	glLinkProgram(programID);
	glGetProgramiv(programID, GL_LINK_STATUS, &iLinkStatus);
	bLinked = iLinkStatus == GL_TRUE;
	return bLinked;
}

void sgl::ShaderProgram::useProgram(){
	if(bLinked){
		glUseProgram(programID);
	}else{
		cout<<"Can't use this program."<<endl;	
	}
}

void sgl::ShaderProgram::deleteProgram(){
	if(!bLinked)
		return;
	bLinked = false;
	glDeleteProgram(programID);
}

GLuint sgl::ShaderProgram::getProgramID(){
	return this->programID;
}
