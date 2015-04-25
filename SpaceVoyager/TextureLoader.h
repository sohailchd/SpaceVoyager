
#ifndef _TextureLoader_
#define _TextureLoader_


#include "MasterHeader.h"
#include "GameStateManager.h"
#include <map>

using namespace std;

class TextureLoader
{

private:

    static GLUquadric* quad_iem;
public:
	
	TextureLoader();
	~TextureLoader();


    GLuint getTextureId(const char* fileNameConstant);
	//static void addToTheList(char* fileNameConstant);
    map<const char*,GLuint>     _textureList;

	TextureLoader* textureLoaderInstance;
};

#endif