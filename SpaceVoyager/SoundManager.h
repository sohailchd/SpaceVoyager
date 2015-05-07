
#ifndef _soundManager_
#define _soundManager_


#include "SoundData.h"
#include <map>

class SoundManager
{


private:
	std::vector<SoundData*> _trackList;
	std::map<soundConstant,SoundData*> _mappedTrackList;
	ISoundEngine* engine2D;
	static SoundManager* smInstance;
	SoundManager();
	~SoundManager();
	bool musicOff;
public:


	int findBySoundConst(soundConstant sc);
	
	void addCurrentPlayList(const char* name , bool l , soundConstant sc);

	void startPlayList();


	void resumeFromPlayList(soundConstant sc);

	void removeFromPlayList(soundConstant sc);
	void pauseFromPlayList(soundConstant sc);

	void setVolFromPlayList(soundConstant sc , int vol);

	void dropAll();

	static SoundManager* getInstance();

	//-----------------
	void playDirectFromEngine(char* fileName, bool isLoop);
	void setMusicState(bool m);
	

};

#endif