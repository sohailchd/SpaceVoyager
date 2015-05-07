/******
           Manager : handles the transition from level-to-level
		   Intent:   In higher verion - to implement complex level flow independent of game_stateManager
*******/


#ifndef __GameSequenceStateManager_
#define __GameSequenceStateManager_

#pragma once

#include "MasterHeader.h"
#include "ISceneNode.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "FightScav.h"

enum SequenceStates
	{
		 levelOneProlougue,
		 inWormhole,
		 dropGenesis
	};




class GameSequenceStateManager
{
private:

	GameSequenceStateManager();
	static GameSequenceStateManager* instance;
	
	ISceneNode* _currentSceneNode;
	SequenceStates _activeInGameSequence;
	SequenceStates _lastInGameSequence;

	void setCurrentScene(SequenceStates sq);


	  // Ad-hoc solutions to ISceneNode manager - - - to be implemented in later versions
		  ISceneNode* lone ;
          ISceneNode* ltwo ;  
          ISceneNode* fightScav_level ;
		  //

public:

	static GameSequenceStateManager* getInstance();
	~GameSequenceStateManager();
	    

		//Game ISceneNode Manager ================
		void setSequenceState(SequenceStates sq);
		SequenceStates getSequenceState();
		ISceneNode* getCurrentISceneNode();

		//=========================================



};


#endif