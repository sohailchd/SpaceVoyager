#include "Shader.h"


static char* textFileRead(const char* fileName)
{
	char* text;
	if(fileName!=NULL)
	{
		FILE *pfile = fopen(fileName,"rt") ;
	
	    if(pfile!=NULL)
	    {
			fseek(pfile,0,SEEK_END);
			int count = ftell(pfile);
			rewind(pfile);

			if(count>0)
			{
				text  = (char*)malloc(sizeof(char*)*(count+1));
				count = fread(text,sizeof(char),count,pfile);
				text[count]='\0';
			}fclose(pfile);

     	}

	}

	return text;
}

Shader::Shader(){}

Shader::Shader(const char* vs_file,const char* fs_file)
{
	init(vs_file,fs_file);
}

void Shader::init(const char* vs_file,const char* fs_file)
{

	glewInit();

	shader_vs = glCreateShader(GL_VERTEX_SHADER);
	shader_fs = glCreateShader(GL_FRAGMENT_SHADER);

	const char* vs_text = textFileRead(vs_file);
	const char* fs_text = textFileRead(fs_file);

	if(vs_text == NULL || fs_text==NULL)
	{
		std::cerr<<"File error. No vertex/fragment shader file found\n";
		return;
	}

	glShaderSource(shader_vs,1,&vs_text,0);
	glShaderSource(shader_fs,1,&fs_text,0);
	glCompileShader(shader_vs);
	glCompileShader(shader_fs);
	shader_id = glCreateProgram();
	glAttachShader(shader_id,shader_vs);
	glAttachShader(shader_id,shader_fs);
	glLinkProgram(shader_id);

}

Shader::~Shader()
{
	glDetachShader( shader_id ,shader_vs);
	glDetachShader( shader_id ,shader_fs);

	glDeleteShader(shader_vs);
	glDeleteShader(shader_fs);
	glDeleteShader(shader_id);

	
}

void Shader::bind()
{
	glUseProgram(shader_id);
}
void Shader::unBind()
{
	glUseProgram(0);
}


unsigned int Shader::id()
{
	return shader_id;
}