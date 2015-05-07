#include "GameStateManager.h"


float GameStateManager::timeSinceStart  = 0;
float GameStateManager::timeSinceLast   = 0;
float GameStateManager::deltaTime       = 0;

GameStateManager* GameStateManager::gsInstance = NULL;


GameStateManager* GameStateManager::getInstance()
{
	if(gsInstance==NULL){ gsInstance = new GameStateManager(); } 
	return gsInstance;
}

GameStateManager::GameStateManager()
{

     _splashScreen = new SplashScreen();
	 _menuScreen   = new MenuScreen();
	 _inGameScreen = new GameScreen();
	 _pauseScreen  = new PauseScreen();
	 _retryScreen  = new RetryScreen();

	 _currentScreen = _splashScreen;
	 _activeGameState = _splash;
	 _lastGameState   = _activeGameState;
}

GameStateManager::~GameStateManager()
{}


void GameStateManager::setGameState(GameStates gs)
{
	setCurrentScreen(gs);
	_lastGameState   = _activeGameState;
	_activeGameState = gs;
	recreateScreen(_lastGameState);

	
	/*SAFE_DELETE(_currentScreen);
    recreateScreen(_activeGameState);
	
	_lastGameState   = _activeGameState;
	_activeGameState = gs;

	setCurrentScreen(_activeGameState);*/

}


void GameStateManager::jumpGameState(GameStates gs)
{
	delete _currentScreen;
	_currentScreen = NULL;
    
	_lastGameState   = _activeGameState;
	_activeGameState = gs;

	setCurrentScreen(_activeGameState);
}

GameStates GameStateManager::getActiveGameState()
{
	return _activeGameState;
}


GameStates GameStateManager::getLastGameState(){ return _lastGameState; }

void GameStateManager::managerEngine() 
{

}

void GameStateManager::setCurrentScreen(GameStates sc)
{
	switch(sc)
	{
	case _splash:
		{ _currentScreen = _splashScreen; }
		break;
	case _menu:
		{ _currentScreen = _menuScreen; }
		break;
	case _inGame:
		{ _currentScreen =  _inGameScreen ; }
		break;
	case _pause:
		{ _currentScreen =  _pauseScreen; }
		break;
	case _retry:
		{ _currentScreen =  _retryScreen; }
		break;
	case _isExiting:
		{
			SAFE_DELETE(_currentScreen);
			SAFE_DELETE(_splashScreen);
			SAFE_DELETE(_menuScreen);
			SAFE_DELETE(_inGameScreen);
			SAFE_DELETE(_retryScreen);
			exit(0);
         }
		break;
	default:
		break;
	}
}

Screens* GameStateManager::getCurrentScreen()
{
	return _currentScreen;
}

void GameStateManager::recreateScreen(GameStates gs)
{
	switch(gs)
	{
	case _splash:
		{
		
			SAFE_DELETE(_splashScreen);
		   _splashScreen = new SplashScreen();
		}
		break;
	case _menu:
		{
		
			SAFE_DELETE(_menuScreen);
		    _menuScreen = new MenuScreen();
		}
		break;
	case _inGame:
		{
			SAFE_DELETE(_inGameScreen);
			_inGameScreen = new GameScreen();
			GameSequenceStateManager::getInstance()->setSequenceState(levelOneProlougue);
		}
		break;
	case _pause:
		{
			SAFE_DELETE(_pauseScreen);
			_pauseScreen = new PauseScreen();
		}
		break;
	case _retry:
		{
			SAFE_DELETE(_retryScreen);
			_retryScreen = new RetryScreen();
		}
		break;
	default:
		break;
	}
}

void GameStateManager::refreshScreenList()
{
	
	_listOfAllScreens.clear();
	_listOfAllScreens.push_back(_splashScreen);
	_listOfAllScreens.push_back(_menuScreen);
	_listOfAllScreens.push_back(_inGameScreen);
	_listOfAllScreens.push_back(_pauseScreen);
	_listOfAllScreens.push_back(_retryScreen);
}


bool GameStateManager::getTriggerAfterSince(GLfloat since , GLfloat interval)
{/*
	while(interval)
	{
        if()
		{
		  --interval;
		}
	}*/
	return false;
}


