#----------------------------------------------------------------
#Makefile para compilar projetos OpenGL
#Autor: Luiz Augusto Volpi Nascimento
#Data: 15/05/2012
#----------------------------------------------------------------

#--------------------------Variáveis-----------------------------
CC=g++
FREEGLUT_INCLUDE=/usr/include/GL
TARGET_NAME=UniformVariables
SOURCE_CODE=main.cpp
GLUT_LIBS=-lGL -lglut -lGLU -lGLEW -lglfw
EXTRA_LIB_FILES=~/Personal\ Workspace/OpenGL/simple-opengl/include/*.cc
#----------------------------------------------------------------
all: build

#compila o código fonte
build: 
	$(CC)  $(EXTRA_INCLUDES) $(EXTRA_LIB_FILES)  $(SOURCE_CODE) -o $(TARGET_NAME)  $(GLUT_LIBS)   

clean:
	
		rm $(TARGET_NAME)
run:
		optirun ./$(TARGET_NAME)
