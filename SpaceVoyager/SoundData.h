
#ifndef _soundData_
#define _soundData_


#include <irrKlang.h>
#include "SoundList.h"
#include <vector>
#include <string>
#include "SoundList.h"
#include <conio.h>
#include <iostream>



using namespace irrklang;

class SoundData
{
private:
	const char* name;  // File-Name with the fully qualified path
	float vol;
	bool loop;
	bool isPaused;
	ISound* instance;
	ISoundEngine* engine;
	soundConstant constId;
	ISoundSource* source;

public:
	SoundData(const char* fileName,bool l , ISoundEngine* eng , soundConstant sc );
	~SoundData();

	void loadSound();  // used when only needs to load sound but not to play
	void directPlay(); 
	void play();       // initialize and play 
	void stop();
	void pause();
	void resume(); 
	void setVol(float v);

	
	const char* getName();
	int getVol();
	ISound* getPlayInstance();	
	soundConstant getSoundConstant();
	

};



#endif