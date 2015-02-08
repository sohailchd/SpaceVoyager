//
//
//#ifndef _soundManager_
//#define _soundManager_
//
//#include <irrKlang.h>
//#include <stdio.h>
//#include <string>
//
//using namespace irrklang;
//using namespace std;
//
///**********************
// 
//***********************/
//
//
//class SManager
//{
//
//private:
//	ISoundEngine* soundEngine;
//
//public:
//	SManager()
//	{
//		soundEngine = createIrrKlangDevice();
//		if(!soundEngine){ printf("Enable to create sound engine."); }
//	}
//
//	~SManager()
//	{
//	}
//
//
//	void playSound2d(char* fileName , bool looped)
//	{
//		soundEngine->play2D(fileName , looped);
//	}
//
//
//	void dropSoundEngine()
//	{
//		soundEngine->drop();
//	}
//
//};
//
//
//#endif