              

#include "GameScreen.h"
#include "levelTwo.h"
#include "levelOne.h"
#include "FightScav.h"






GameScreen::GameScreen()
{

	lone = new levelTwo();
	ltwo = new levelOne();
	fightScav_level = new fightScav();


	_currentSceneNode = lone;
	_activeInGameSequence = _inPrologue_SQ;
}

GameScreen::~GameScreen()
{
}

void  GameScreen::display_screen()
{
	_currentSceneNode->display_fn_game();
}


void GameScreen::idle_screen()
{
	_currentSceneNode->idle_fn_game();
}

void GameScreen::keyboard_screen(unsigned char& key , int& x , int& y)
{
	_currentSceneNode->keyboard_fn_game(key,x,y);
}


void GameScreen::loadObjects()
{
	
}

void GameScreen::keyboard_screen_sp(int& key , int& x, int& y)
{
	_currentSceneNode->special_fn_game(key,x,y);
}


void GameScreen::reshape(int& w , int& h)
{
  	int w1 = glutGet(GLUT_WINDOW_WIDTH);
	int h1 = glutGet(GLUT_WINDOW_HEIGHT);

  glViewport(0, 0, w1, h1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (GLfloat)w1*1.0 / (GLfloat)h1, 1.0, FAR_SIGHT);
  glMatrixMode(GL_MODELVIEW);
  
}

void GameScreen::timer_screen(int t)
{
	_currentSceneNode->timer_fn_game(t);
}

void GameScreen::setSequenceState(SequenceStates st)
{

	switch (st)
	{
	case _inPrologue_SQ:
		{
			SAFE_DELETE(lone);
			lone = new levelTwo();
			_currentSceneNode = lone;
			_activeInGameSequence = _inPrologue_SQ;
		}
	  break;
	case _inWormHole_SQ:
		{
			SAFE_DELETE(fightScav_level);
			fightScav_level = new fightScav();
			_currentSceneNode = fightScav_level;
			_activeInGameSequence = _inWormHole_SQ;
		}
		break;
	case _inFightScav_SQ:
		{
		}
		break;
	case _inDropGenesis_SQ:
		break;
	case _inEpilogue_SQ:
		break;
	default:
		break;
	}
}

