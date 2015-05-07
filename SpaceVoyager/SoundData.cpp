


#include "SoundData.h"

SoundData::SoundData(const char* fileName,bool l , ISoundEngine* eng , soundConstant sc )
	{
		name = fileName;
		loop = l;
		isPaused = true;
		engine = eng;
		vol = DEFAULT_VOLUME;
		constId = sc;
		instance = NULL;
		isPlaying = false;
		source = engine->addSoundSourceFromFile(fileName);
	}

SoundData::~SoundData()
{

}


void SoundData::loadSound()
{
	 instance = engine->play2D(name,loop,true,true); 
}

void SoundData::play()
{

	
	if(instance && !isPaused)
	   {
		   instance->setIsPaused(false);
	   }
	else
	{
		if(!isPlaying){
		instance = engine->play2D(name,loop,false,true);
		isPlaying = true;
		}
		
	}

}


void SoundData::stop(){ if(instance!=NULL) instance->stop(); }
void SoundData::pause(){  if(instance){instance->setIsPaused(true);} isPaused=true;}
void SoundData::resume(){ if(instance){ instance->setIsPaused(false);} isPaused = false;  }  
void SoundData::setVol(float v)
{
	vol = (v<=100.0f && v>=0.0f)?v:DEFAULT_VOLUME; 
	if(instance!=NULL){instance->setVolume(v);}
	
}
	
const char* SoundData::getName(){ return name; }
int SoundData::getVol(){ return vol; }
ISound* SoundData::getPlayInstance()
{
		if(instance!=NULL) {return instance; } 
		else { return NULL;} 
}
soundConstant SoundData::getSoundConstant()
{
	return constId;
}