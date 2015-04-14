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

}

GameStateManager::~GameStateManager()
{}


void GameStateManager::setGameState(GameStates gs)
{

	delete _currentScreen;
	_currentScreen = NULL;
    recreateScreen(_activeGameState);
	
	_lastGameState   = _activeGameState;
	_activeGameState = gs;

	setCurrentScreen(_activeGameState);

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
		//delete _splashScreen;
		_splashScreen = NULL;
		_splashScreen = new SplashScreen();
		}
		break;
	case _menu:
		{
		//delete _menuScreen;
		_menuScreen = NULL;
		_menuScreen = new MenuScreen();
		}
		break;
	case _inGame:
		{
			//delete _inGameScreen ;
			_inGameScreen = NULL;
			_inGameScreen = new GameScreen();
		}
		break;
	case _pause:
		{
			//delete _pauseScreen;
			_pauseScreen = NULL;
			_pauseScreen = new PauseScreen();
		}
		break;
	case _retry:
		{
			//delete _retryScreen;
			_retryScreen = NULL;
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