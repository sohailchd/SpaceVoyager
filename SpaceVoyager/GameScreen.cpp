              
#include "GameScreen.h"



GameScreen::GameScreen()
{

}

GameScreen::~GameScreen()
{
}

void  GameScreen::display_screen()
{
	GameSequenceStateManager::getInstance()->getCurrentISceneNode()->display_fn_game();
}


void GameScreen::idle_screen()
{
	GameSequenceStateManager::getInstance()->getCurrentISceneNode()->idle_fn_game();
}

void GameScreen::keyboard_screen(unsigned char& key , int& x , int& y)
{
	GameSequenceStateManager::getInstance()->getCurrentISceneNode()->keyboard_fn_game(key,x,y);
}


void GameScreen::loadObjects()
{
	
}

void GameScreen::keyboard_screen_sp(int& key , int& x, int& y)
{
	GameSequenceStateManager::getInstance()->getCurrentISceneNode()->special_fn_game(key,x,y);
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
	GameSequenceStateManager::getInstance()->getCurrentISceneNode()->timer_fn_game(0);
}


