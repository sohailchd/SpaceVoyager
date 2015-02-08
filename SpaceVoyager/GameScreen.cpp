              

#include "GameScreen.h"
#include "levelTwo.h"
#include "levelOne.h"




ISceneNode* lone = new levelTwo();
ISceneNode* ltwo = new levelOne();


GameScreen::GameScreen()
{


}

GameScreen::~GameScreen()
{
}

void  GameScreen::display_screen()
{
	lone->display_fn_game();

	switch (GameStateManager::_currentSequence)
	{
	case GameStateManager::_inPrologue_SQ:
		{}
		break;
	case GameStateManager::_inSequenceLoad_SQ:
		{}
		break;
	case GameStateManager::_inAttack_SQ:
		{}
		break;
	case GameStateManager::_inWormHole_SQ:
		{}
		break;
	case GameStateManager::_inFightScav_SQ:
		{}
		break;
	case GameStateManager::_inDropGenesis_SQ:
		{}
		break;
    case GameStateManager::_missionEnd:
		break;
	default:
		break;
	}
}


void GameScreen::idle_screen()
{
   lone->idle_fn_game();
   glutPostRedisplay();
 
   	switch (GameStateManager::_currentSequence)
	{
	case GameStateManager::_inPrologue_SQ:
		{}
		break;
	case GameStateManager::_inSequenceLoad_SQ:
		{}
		break;
	case GameStateManager::_inAttack_SQ:
		{}
		break;
	case GameStateManager::_inWormHole_SQ:
		{}
		break;
	case GameStateManager::_inFightScav_SQ:
		{}
		break;
	case GameStateManager::_inDropGenesis_SQ:
		{}
		break;
	case GameStateManager::_missionEnd:
		break;
	default:
		break;
	}
}

void GameScreen::keyboard_screen(unsigned char& key , int& x , int& y)
{
 lone->keyboard_fn_game(key,x,y);
 
 	switch (GameStateManager::_currentSequence)
	{
	case GameStateManager::_inPrologue_SQ:
		{}
		break;
	case GameStateManager::_inSequenceLoad_SQ:
		{}
		break;
	case GameStateManager::_inAttack_SQ:
		{}
		break;
	case GameStateManager::_inWormHole_SQ:
		{}
		break;
	case GameStateManager::_inFightScav_SQ:
		{}
		break;
	case GameStateManager::_inDropGenesis_SQ:
		{}
		break;
    case GameStateManager::_missionEnd:
		break;
	default:
		break;
	}
}


void GameScreen::loadObjects()
{
       
}

void GameScreen::keyboard_screen_sp(int& key , int& x, int& y)
{
  lone->special_fn_game(key,x,y);
  
  	switch (GameStateManager::_currentSequence)
	{
	case GameStateManager::_inPrologue_SQ:
		{}
		break;
	case GameStateManager::_inSequenceLoad_SQ:
		{}
		break;
	case GameStateManager::_inAttack_SQ:
		{}
		break;
	case GameStateManager::_inWormHole_SQ:
		{}
		break;
	case GameStateManager::_inFightScav_SQ:
		{}
		break;
	case GameStateManager::_inDropGenesis_SQ:
		{}
		break;
    case GameStateManager::_missionEnd:
		break;
	default:
		break;
	}

}


void GameScreen::reshape(int& w , int& h)
{
  /*glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (GLfloat)w*0.8 / (GLfloat)h, 1.0, FAR_SIGHT);
  glMatrixMode(GL_MODELVIEW);*/
  
}

void GameScreen::timer_screen(int t)
{
       lone->timer_fn_game(t);

	switch (GameStateManager::_currentSequence)
	{
	case GameStateManager::_inPrologue_SQ:
		{}
		break;
	case GameStateManager::_inSequenceLoad_SQ:
		{}
		break;
	case GameStateManager::_inAttack_SQ:
		{}
		break;
	case GameStateManager::_inWormHole_SQ:
		{}
		break;
	case GameStateManager::_inFightScav_SQ:
		{}
		break;
	case GameStateManager::_inDropGenesis_SQ:
		{}
		break;
	case GameStateManager::_missionEnd:
		break;
	default:
		break;
	}
}



