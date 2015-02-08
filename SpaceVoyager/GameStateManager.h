
#ifndef _gsManager
#define _gsManager

#pragma once

#include "ISceneNode.h"
#include <vector>


class GameStateManager
{
      public:
        GameStateManager();
        ~GameStateManager();    
            
          static enum GameStates{
                _splash,
                _menu, 
                _inGame,
                _pause,
                _isExiting
          };
          
          static GameStates _activeState;
		  static GameStates _lastState;
          
          
          static  float timeSinceStart;
          static  float timeSinceLast;
          static  float deltaTime;
          static void setState(GameStateManager::GameStates  gs);


    /* Sequence Manager */
	static enum SequenceStates
	{
		 _inPrologue_SQ,
		 _inAttack_SQ,
		 _inSequenceLoad_SQ,   /* Docking with the UNITY */
		 _inWormHole_SQ,
		 _inFightScav_SQ,
		 _inDropGenesis_SQ,
		 _inEpilogue_SQ,
		 _missionEnd
	};

	static SequenceStates _currentSequence;
	static SequenceStates _lastSequence;
	static std::vector<ISceneNode*> _sequenceList;
	static char* currentObjective_text;

    static void addToSequenceList(ISceneNode* node);
	static void setSequence(GameStateManager::SequenceStates st);

    void managerEngine();
      
};


#endif
