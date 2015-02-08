

#ifndef _soundManager_
#define _soundManager_

#include <irrKlang.h>
#include <stdio.h>
#include <string>

#define SPLASH_SND "../audio/Splash.mp3"
#define AMBIANCE_SND "../audio/craft/ambiance.wav"
#define DIALOGUE_ONE "../audio/craft/dialogue1.mp3"

using namespace irrklang;
using namespace std;





class SManager
{

private:
	ISoundEngine* soundEngine;
	ISoundEngine* musicEngine;
public:
	SManager()
	{
		soundEngine = createIrrKlangDevice();
		musicEngine = createIrrKlangDevice();

		if(!soundEngine || !musicEngine){ printf("Enable to create sound engine."); }
	}

	~SManager()
	{
	}


	void playSound2d(char* fileName , bool looped)
	{
		soundEngine->play2D(fileName , looped);
	}

	void playMusic2d(char* filename,bool loop)
	{
		musicEngine->play2D(filename,loop);
	}


	void dropSoundEngine()
	{
		soundEngine->drop();
	}

};


#endif