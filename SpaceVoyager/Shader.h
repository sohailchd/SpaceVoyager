
#ifndef _SHADER_H
#define _SHADER_H


#include <iostream>
#include <glew.h>
#include <freeglut.h>
//#include <gl\GL.h>
#include <string>
#include <stdlib.h>
#include <freeglut_ext.h>


#pragma comment(lib, "glew32.lib")

class Shader
{
public:
	Shader();
	~Shader();

	Shader(const char* vsFile,const char* fsFile);
	void init(const char* vsFile,const char* fsFile);

	void bind();
	void unBind();
	unsigned int id();


private:
	unsigned int shader_id;
	unsigned int shader_vs;
	unsigned int shader_fs;

};


#endif