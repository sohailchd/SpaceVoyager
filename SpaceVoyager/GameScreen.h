

#ifndef _GameScreen_
#define _GameScreen_


#include "Screens.h"
#include "ISceneNode.h"
#include "GameStateManager.h"

#pragma once


enum SequenceStates
	{
		 _inPrologue_SQ,       /* Audio intro */
		 _inAttack_SQ,         /* About the attack - audio */
		 _inSequenceLoad_SQ,   /* Docking with the UNITY */
		 _inWormHole_SQ,       /* start the wormhole */
		 _inFightScav_SQ,      /* inWormHole  */
		 _inDropGenesis_SQ,    /* dropThe genesis */
		 _inEpilogue_SQ,       
		 _missionEnd
	};

class GameScreen : public Screens
{


private:
		  SequenceStates _activeInGameSequence;
		  SequenceStates _lastInGameSequence;
          
		  void setCurrentSceneNodeInstance(ISceneNode* node);

		  //---------------------------
		  ISceneNode* lone ;
          ISceneNode* ltwo ;  
          ISceneNode* fightScav_level ;
		  //---------------------------

		  ISceneNode* _currentSceneNode;

 public:
 
	 GameScreen();
	 ~GameScreen();

	
        virtual void display_screen();
        virtual void keyboard_screen(unsigned char& key , int& x , int& y);
        virtual void timer_screen(int t);
        virtual void idle_screen();
        virtual void keyboard_screen_sp(int& key , int& x , int& y);
        virtual void loadObjects();  // later versions
        virtual void reshape(int& w , int& h); 

		void setSequenceState(SequenceStates sq);
		SequenceStates getSequenceState();

		
		ISceneNode* getCurrentSceneNodeInstance();
		

};





#endif
