#include "GameSequenceStateManager.h"

GameSequenceStateManager* GameSequenceStateManager::instance = NULL;
GameSequenceStateManager* GameSequenceStateManager::getInstance() 
{
	if(instance==NULL)
	{
		instance = new GameSequenceStateManager();
	}
	return instance;
}

GameSequenceStateManager::GameSequenceStateManager()
{
	lone = new levelTwo();
	ltwo = new levelOne();
	fightScav_level = new fightScav(); 

	_activeInGameSequence = levelOneProlougue;
	_currentSceneNode     = lone;
}

GameSequenceStateManager::~GameSequenceStateManager()
{
	SAFE_DELETE(lone);
	SAFE_DELETE(ltwo);
	SAFE_DELETE(fightScav_level);
	SAFE_DELETE(_currentSceneNode);
}


void GameSequenceStateManager::setSequenceState(SequenceStates sq)
{
	switch (sq)
	{
	case levelOneProlougue:
		{
			_activeInGameSequence = sq;
			setCurrentScene(_activeInGameSequence);
		}
		break;
	case inWormhole:
		{
			_activeInGameSequence = sq;
			setCurrentScene(_activeInGameSequence);
		}
		break;
	case dropGenesis:
		{
			_activeInGameSequence = sq;
			setCurrentScene(_activeInGameSequence);
		}
		break;
	default:
		break;
	}
}


void GameSequenceStateManager::setCurrentScene(SequenceStates sq)
{
	switch (sq)
	{
	case levelOneProlougue:
		{
			SAFE_DELETE(lone);
			lone = new levelTwo();
			_currentSceneNode = lone;
		}
		break;
	case inWormhole:
		{
			SAFE_DELETE(fightScav_level);
			fightScav_level = new fightScav();
			_currentSceneNode = fightScav_level;
		}
		break;
	case dropGenesis:
		{
			SAFE_DELETE(ltwo);
			ltwo = new levelOne();
			_currentSceneNode = ltwo;
		}
		break;
	default:
		break;
	}
}

ISceneNode* GameSequenceStateManager::getCurrentISceneNode()
{
	return _currentSceneNode;
}

SequenceStates GameSequenceStateManager::getSequenceState()
{
	return _activeInGameSequence;
}


