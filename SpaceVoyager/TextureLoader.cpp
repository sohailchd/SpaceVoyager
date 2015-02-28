#include "TextureLoader.h"



TextureLoader::TextureLoader()
{
}

TextureLoader::~TextureLoader()
{

}


GLuint TextureLoader::getTextureId(const char* fileNameConstant)
{
	GLuint tex_id = 0;

	if(_textureList[fileNameConstant]==0)
	{
	glEnable(GL_NORMALIZE);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(MAX_NO_TEXTURE, &tex_id);
	
		tex_id = SOIL_load_OGL_texture(
			fileNameConstant,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_POWER_OF_TWO
			| SOIL_FLAG_MIPMAPS
			//SOIL_FLAG_MIPMAPS
			//| SOIL_FLAG_MULTIPLY_ALPHA
			//| SOIL_FLAG_COMPRESS_TO_DXT
			| SOIL_FLAG_DDS_LOAD_DIRECT
			//| SOIL_FLAG_NTSC_SAFE_RGB
			//| SOIL_FLAG_CoCg_Y
			);
		if (tex_id < 0)
			printf("Error in loading %s\n", fileNameConstant);
		_textureList[fileNameConstant]=tex_id;
	  }
	else
	{
        tex_id = _textureList[fileNameConstant];
	}
	
	return _textureList[fileNameConstant];
	    
}
