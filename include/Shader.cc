#include "../lib/Shader.h"

bool sgl::Shader::loadShader(string sFile,int type){ 
	   FILE* fp = fopen(sFile.c_str(), "rt"); 
	   if(!fp)return false; 

	   // Get all lines from a file

	   vector<string> sLines; 
	   char sLine[255]; 
	   while(fgets(sLine, 255, fp)){
		sLines.push_back(sLine);
		
		} 
	   fclose(fp); 
	
	   const char** sProgram = new const char*[sLines.size()]; 
	   for(int i = 0;i < sLines.size(); i++)
		sProgram[i] = sLines[i].c_str(); 
	    
	   shaderID = glCreateShader(type); 

	   glShaderSource(shaderID, sLines.size(), sProgram, NULL); 
	   glCompileShader(shaderID); 

	   delete[] sProgram; 

	   int iCompilationStatus; 
	   glGetShaderiv(shaderID, GL_COMPILE_STATUS, &iCompilationStatus); 

	   if(iCompilationStatus == GL_FALSE){
		cout<<"Failed to load the shader"<<endl;
		return false; 
	   }
	   cout<<"Shader loaded successfully"<<endl;
	   shaderType = type; 
	   iLoaded = true; 

	   return 1; 
}

GLuint sgl::Shader::getShaderID(){
	return this->shaderID;
}

bool sgl::Shader::isLoaded(){
	return this->iLoaded;
}

void sgl::Shader::deleteShader(){
	if(!isLoaded())
		return;
	iLoaded = false;
	glDeleteShader(shaderID);
}
