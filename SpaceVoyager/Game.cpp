


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

    	    screenList.push_back(_splashScreen);
            screenList.push_back(_menuScreen);
            screenList.push_back(_inGameScreen);

			//std::thread t1(parallelTextureLoader);

}

Game::~Game()
{
	delete _splashScreen;
	delete _menuScreen;
	delete _inGameScreen;
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

      switch(GameStateManager::_activeState)
      {
            case GameStateManager::_splash :
               screenList[0]->display_screen();
               break;
            case GameStateManager::_menu :
               screenList[1]->display_screen();
               break;   
            case GameStateManager::_inGame :
                screenList[2]->display_screen();
                break; 
            case GameStateManager::_pause:
                //printf("Game is PAUSED.\n");
                break;    
            case GameStateManager::_isExiting:
                printf("Game is EXITING.\n");
                break;    
            default:
                break;      
      }
     glutPostRedisplay();
}

void Game::timer_fn_game(int t)
{

  

    switch(GameStateManager::_activeState)
      {
            case GameStateManager::_splash :
               screenList[0]->timer_screen(t);
               break;
            case GameStateManager::_menu :
               screenList[1]->timer_screen(t);
               break;   
            case GameStateManager::_inGame :
                screenList[2]->timer_screen(0);
                break; 
            case GameStateManager::_pause:
                //printf("Game is PAUSED.\n");
                break;    
            case GameStateManager::_isExiting:
                printf("Game is EXITING.\n");
                break;    
            default:
                break;      
      }
     //glutPostRedisplay();
}
        
void Game::idle_fn_game()
{
      switch(GameStateManager::_activeState)
      {
            case GameStateManager::_splash :
               screenList[0]->idle_screen();
               break;
            case GameStateManager::_menu :
               screenList[1]->idle_screen();
               break;   
            case GameStateManager::_inGame :
                screenList[2]->idle_screen();
                break; 
            case GameStateManager::_pause:
                //printf("Game is PAUSED.\n");
                break;    
            case GameStateManager::_isExiting:
                printf("Game is EXITING.\n");
                break;    
            default:
                break;      
      }
     glutPostRedisplay();
}
    

void Game::keyboard_fn_game(unsigned char& key , int& x , int& y)
{
      switch(GameStateManager::_activeState)
      {
            case GameStateManager::_splash :
               screenList[0]->keyboard_screen(key,x,y);
               break;
            case GameStateManager::_menu :
               screenList[1]->keyboard_screen(key,x,y);
               break;   
            case GameStateManager::_inGame :
                screenList[2]->keyboard_screen(key,x,y);
                break; 
            case GameStateManager::_pause:
                //printf("Game is PAUSED.\n");
                break;    
            case GameStateManager::_isExiting:
                printf("Game is EXITING.\n");
                break;    
            default:
                break;      
      }

	  if((key=='P' || key=='p'))
	  {
		  if(!pause_toggle)
		  {
		  GameStateManager::setState(GameStateManager::_pause);
		  pause_toggle = true;
		  }
		  else{
			  GameStateManager::setState(GameStateManager::_lastState);
			  pause_toggle = false;
		  }
	  }


      glutPostRedisplay();
}





void Game::keyboard_fn_game_sp(int& key , int& x , int& y)
{
      switch(GameStateManager::_activeState)
      {
            case GameStateManager::_splash :
               screenList[0]->keyboard_screen_sp(key,x,y);
               break;
            case GameStateManager::_menu :
               screenList[1]->keyboard_screen_sp(key,x,y);
               break;   
            case GameStateManager::_inGame :
                screenList[2]->keyboard_screen_sp(key,x,y);
                break; 
            case GameStateManager::_pause:
                printf("Game is PAUSED.\n");
                break;    
            case GameStateManager::_isExiting:
                printf("Game is EXITING.\n");
                break;    
            default:
                break;      
      }
      
      glutPostRedisplay();
}


void Game::reshape(int& w , int& h)
{
       switch(GameStateManager::_activeState)
      {
            case GameStateManager::_splash :
               screenList[0]->reshape(w,h);
               break;
            case GameStateManager::_menu :
               screenList[1]->reshape(w,h);
               break;   
            case GameStateManager::_inGame :
                screenList[2]->reshape(w,h);
                break; 
            case GameStateManager::_pause:
                printf("Game is PAUSED.\n");
                break;    
            case GameStateManager::_isExiting:
                printf("Game is EXITING.\n");
                break;    
            default:
                break;      
      }     
      glutPostRedisplay();
      
}







