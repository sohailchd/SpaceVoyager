#pragma once

#include <irrKlang.h>


using namespace irrklang;

class XSoundManager
{

public:

	XSoundManager();
	~XSoundManager();

	ISoundEngine* engine2D;

	void playSoundByFileName(const char* fileName,bool repeat);
	void removeSoundByFileName(const char* fileName);

};