
#ifndef _gsManager
#define _gsManager

#pragma once


#include <vector>
#include "MasterHeader.h"
#include "Screens.h"
#include "SplashScreen.h"
#include "GameScreen.h"
#include "MenuScreen.h"
#include "RetryScreen.h"
#include "PauseScreen.h"



//#define SPLASH_SCREEN 0
//#define MENU_SCREEN   1
//#define INGAME_SCREEN 2
//#define PAUSE_SCREEN  3
//#define RETRY_SCREEN  4


enum GameStates
         {
                _splash,
                _menu, 
                _inGame,
                _pause,
                _isExiting,
				_retry
          };
          




class GameStateManager
{
private:
          GameStates _activeGameState;
		  GameStates _lastGameState;
		  Screens   *_currentScreen;



		  vector<Screens*>  _listOfAllScreens;  // Later versions
		 
		  // Ad-hoc solutions------
		  Screens* _splashScreen;
		  Screens* _menuScreen;
		  Screens* _inGameScreen;
		  Screens* _pauseScreen;
		  Screens* _retryScreen;
		  //---------------------

		  static GameStateManager* gsInstance;
		  GameStateManager();
          void setCurrentScreen(GameStates sc); // Can only be set by the defined logic in game-manager --- to be implemnted in later versions
public:
          
         ~GameStateManager();    
            
		  static GameStateManager* getInstance();
          
          
          static  float timeSinceStart;
          static  float timeSinceLast;
          static  float deltaTime;
          
		  
		  /*--------------------------------------------------------------
		        Change the _currentGameState -> exited
				Delete the _currentScreen and assingn new
				Create the instance of new Screen as per the -> GameState
				Change the next _currentGameState -> _active*/
		  void  setGameState(GameStates  gs);

		  
		  /*-------------------------------------------------------------
		        Change the _currentGameState -> exited
				keep the current instance of the screen -> to be used later
				Create the instance of new Screen as per the -> GameState
				Change the next _currentGameState -> _active */
		  void jumpGameState(GameStates gs);    /* this is too transform to another state without the deleting the current state */  
		  

		  GameStates getActiveGameState();
		  GameStates getLastGameState();
		 
		  
		  
		  //to be used by the Game-Class
		  Screens* getCurrentScreen();
		  void recreateScreen(GameStates gs);


		 

		  /*
		        ListScreens:
				If any of the states of the screens has changed to _exited
				then delete the list and create a new instance.
		  */
	      void managerEngine();
		  void refreshScreenList();
		  bool getTriggerAfterSince(GLfloat since , GLfloat interval);


};


#endif
