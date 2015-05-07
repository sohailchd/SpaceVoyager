#include "SoundManager.h"


SoundManager* SoundManager::smInstance = NULL;

SoundManager* SoundManager::getInstance()
{
	if(smInstance==NULL)
	{
		smInstance = new SoundManager();
	}

	return smInstance;
}

	SoundManager::SoundManager()
	{
		engine2D = createIrrKlangDevice();
		musicOff = false;
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


		return NULL;
	}

	void SoundManager::addCurrentPlayList(const char* name , bool l , soundConstant sc)
	{
		/*if(findBySoundConst(sc)==NULL)
		{
		  _trackList.push_back(new SoundData(name,l,engine2D,sc));
		}else
		{
			_trackList[findBySoundConst(sc)]->play();
		}*/
		
		if(_mappedTrackList[sc]==NULL)
		{
			_mappedTrackList[sc] = new SoundData(name,l,engine2D,sc);
		}
	}

	void SoundManager::startPlayList()
	{
		/*if(_trackList.size()!=0)
		{
		for(int i=0;i<_trackList.size();i++)
		 {
			 if(!_trackList[i]->getIsplaying())
			 {
			  _trackList[i]->play();
			 }
		 }

		}*/
		if(_mappedTrackList.size()!=0 && !musicOff)
		{
		for(std::map<soundConstant,SoundData*>::iterator it = _mappedTrackList.begin();it!=_mappedTrackList.end();++it)
		{
			it->second->play();
		}
		}
	}

	void SoundManager::resumeFromPlayList(soundConstant sc)
	{
		_mappedTrackList[sc]->resume();
	}

	void SoundManager::removeFromPlayList(soundConstant sc)
	{
		/*_trackList[findBySoundConst(sc)]->stop();
		_trackList.erase(_trackList.begin()+findBySoundConst(sc));*/
		
		_mappedTrackList[sc]->stop();
		
	}
	void SoundManager::pauseFromPlayList(soundConstant sc)
	{
		_mappedTrackList[sc]->pause();
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

	void SoundManager::playDirectFromEngine(char* fname,bool isLoop)
	{
		engine2D->play2D(fname,isLoop,false,true);
	}

	void SoundManager::setMusicState(bool m )
	{
		musicOff = m;
	}