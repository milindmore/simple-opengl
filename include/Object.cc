#include "../lib/Object.h"

sgl::Object::Object(){
	this->hasColor = false;
	transformations[0][0] = 1.0f; transformations[0][1] = 0.0f; transformations[0][2] = 0.0f; transformations[0][3] = 0.0f;
	transformations[1][0] = 0.0f; transformations[1][1] = 1.0f; transformations[1][2] = 0.0f; transformations[1][3] = 0.0f;
	transformations[2][0] = 0.0f; transformations[2][1] = 0.0f; transformations[2][2] = 1.0f; transformations[2][3] = 0.0f;
	transformations[3][0] = 0.0f; transformations[3][1] = 0.0f; transformations[3][2] = 0.0f; transformations[3][3] = 1.0f;
	
}

sgl::Object::Object(std::vector<glm::vec3> vertices){
	for(int i = 0; i < vertices.size(); i++)
		this->vertices.push_back(vertices[i]);
	
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, this->vertices.size()*sizeof(glm::vec3),&(this->vertices[0]), GL_STATIC_DRAW);
}

sgl::Object::~Object(){
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDeleteBuffers(1,&(this->vertexBuffer));
		glDeleteBuffers(1,&(this->colorBuffer));
}



void sgl::Object::render(GLenum mode){
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glVertexAttribPointer(
		0, // The attribute we want to configure
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	if(this->hasColor){
		//cout<<"existe cor"<<" "<<color.size()<<endl;
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, this->colorBuffer);
		glVertexAttribPointer(
			1,    // The attribute we want to configure
			3,                            // size
			GL_FLOAT,                     // type
			GL_FALSE,                     // normalized?
			0,                            // stride
			(void*)0                      // array buffer offset
		);
	
	}
	
	
	glDrawArrays(mode, 0, vertices.size());
	glDisableVertexAttribArray(0);
	if(this->hasColor)
		glDisableVertexAttribArray(2);


}

void sgl::Object::setColor(std::vector<glm::vec3> color){
	for(int i = 0; i < color.size(); i++)
		this->color.push_back(color[i]);
	glGenBuffers(1, &(this->colorBuffer));
	glBindBuffer(GL_ARRAY_BUFFER, this->colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, color.size()*sizeof(glm::vec3),&(this->color[0]), GL_STATIC_DRAW);
	this->hasColor = true;
}

void sgl::Object::setVertices(std::vector<glm::vec3> vertices){
	for(int i = 0; i < vertices.size(); i++)
		this->vertices.push_back(vertices[i]);
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(glm::vec3),&(this->vertices[0]), GL_STATIC_DRAW);
}

//transformations

void sgl::Object::translate(glm::vec3 v){
	transformations[0][3]=v[0];
	transformations[1][3]=v[1];
	transformations[2][3]=v[2];
}

glm::mat4 sgl::Object::getTransformationsMatrix(){
	return transformations;
}

