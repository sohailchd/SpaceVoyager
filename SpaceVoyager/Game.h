

#ifndef _game_
#define _game_

#pragma once

#include "MasterHeader.h"
#include "Screens.h"
#include "SplashScreen.h"
#include "GameScreen.h"
#include "MenuScreen.h"
#include <thread>
#include "IEntityManager.h"

class Game{
    
private:
	static Game* gameInstance;

public:
    
    	enum GameStates { 
    	_splash , 
    	_menu ,
    	_inGame ,
    	_pause ,
    	_isExiting
    	};
    	static GameStates _activeState;
        

    	~Game(){};
    	


        void display_fn_game();
        void timer_fn_game(int t);
        void idle_fn_game();
        void keyboard_fn_game(unsigned char& key , int& x , int& y);
        void keyboard_fn_game_sp(int& key , int& x , int& y);
        void reshape(int& w, int& h);
        
        static Game* getInstance();


        Screens* _splashScreen;
        Screens* _menuScreen;
        Screens* _inGameScreen;
        std::vector<Screens*> screenList;

protected:
	Game()
	{
			
	        _splashScreen = new SplashScreen();
            _menuScreen   = new MenuScreen();
            _inGameScreen = new GameScreen();

    	    screenList.push_back(_splashScreen);
            screenList.push_back(_menuScreen);
            screenList.push_back(_inGameScreen);

		

            printf("initFunc:: called.\n");
	
	}

};




#endif
