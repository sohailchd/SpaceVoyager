#include "SoundManager.h"





	SoundManager::SoundManager()
	{
		engine2D = createIrrKlangDevice();
	}

	SoundManager::~SoundManager(){}

	int SoundManager::findBySoundConst(soundConstant sc)
	{
		for(int i=0;i<_trackList.size();i++)
		 {
			 if(_trackList[i]->getSoundConstant()==sc)
			 {
				 return i;
			 }
		 }
	}

	void SoundManager::addCurrentPlayList(const char* name , bool l , soundConstant sc)
	{
		_trackList.push_back(new SoundData(name,l,engine2D,sc));
		
	}

	void SoundManager::startPlayList()
	{
		for(int i=0;i<_trackList.size();i++)
		 {
			 _trackList[i]->play();
		 }
	}


	void SoundManager::resumeFromPlayList(soundConstant sc)
	{
		_trackList[findBySoundConst(sc)]->resume();
	}

	void SoundManager::removeFromPlayList(soundConstant sc)
	{
		_trackList[findBySoundConst(sc)]->stop();
		_trackList.erase(_trackList.begin()+findBySoundConst(sc));
	}
	void SoundManager::pauseFromPlayList(soundConstant sc)
	{
		_trackList[findBySoundConst(sc)]->pause();
	}

	void SoundManager::setVolFromPlayList(soundConstant sc , int vol)
	{
		_trackList[findBySoundConst(sc)]->setVol(vol);
	}

	void SoundManager::dropAll()
	{
		for(int i=0;i<_trackList.size();i++)
		 {
			 _trackList[i]->stop();
		 }
		engine2D->drop();
	}