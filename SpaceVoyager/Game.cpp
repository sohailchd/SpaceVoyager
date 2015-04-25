


#include "MasterHeader.h"
#include "Game.h"
#include "GameStateManager.h"



bool pause_toggle = false;
Game* Game::gameInstance = NULL;


Game::Game()
{
	        _splashScreen = new SplashScreen();
            _menuScreen   = new MenuScreen();
            _inGameScreen = new GameScreen();
			_retryScreen  = new RetryScreen();

}

Game::~Game()
{
	delete _splashScreen;
	delete _menuScreen;
	delete _inGameScreen;
	delete _retryScreen;

	delete IEntityManager::getInstance();
	SoundManager::getInstance()->dropAll();
}

Game* Game::getInstance()
{
	if(Game::gameInstance==NULL)
	{
		Game::gameInstance = new Game();
	}

	return Game::gameInstance;

}




void Game::display_fn_game()
{

	 GameStateManager::getInstance()->getCurrentScreen()->display_screen();
     glutPostRedisplay();
}

void Game::timer_fn_game(int t)
{
	GameStateManager::getInstance()->getCurrentScreen()->timer_screen(t);
	glutPostRedisplay();
}
        
void Game::idle_fn_game()
{
	GameStateManager::getInstance()->getCurrentScreen()->timer_screen(0);
	GameStateManager::getInstance()->getCurrentScreen()->display_screen();
     glutPostRedisplay();
}
    

void Game::keyboard_fn_game(unsigned char& key , int& x , int& y)
{
	GameStateManager::getInstance()->getCurrentScreen()->keyboard_screen(key,x,y);
      glutPostRedisplay();
}





void Game::keyboard_fn_game_sp(int& key , int& x , int& y)
{
	  GameStateManager::getInstance()->getCurrentScreen()->keyboard_screen_sp(key,x,y);
      glutPostRedisplay();
}


void Game::reshape(int& w , int& h)
{
  
	GameStateManager::getInstance()->getCurrentScreen()->reshape(w,h);
}







