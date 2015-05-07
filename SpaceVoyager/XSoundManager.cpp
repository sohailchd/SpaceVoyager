#include "XSoundManager.h"

XSoundManager::XSoundManager()
{
	engine2D = createIrrKlangDevice();
}

XSoundManager::~XSoundManager()
{
	engine2D->removeAllSoundSources();
	engine2D->drop();
}

void XSoundManager::playSoundByFileName(const char* fileName,bool repeat)
{
	engine2D->play2D(fileName,repeat,false,false);
}

void XSoundManager::removeSoundByFileName(const char* fileName)
{
	engine2D->removeSoundSource(fileName);
}