

#ifndef _game_
#define _game_

#pragma once

#include "GameStateManager.h"

class Game{
    
private:
	static Game* gameInstance;

public:
    
    	enum GameStates { 
    	_splash , 
    	_menu ,
    	_inGame ,
    	_pause ,
    	_isExiting,
		_retry
    	};
    	
    	~Game();
    	


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
		Screens* _retryScreen;

        std::vector<Screens*> screenList;
		template<class fwdIter , class T> void replace(fwdIter fs , fwdIter lst , const T& old , const T& newV)		{
			while(fs!=lst)
			{
				if(*fs==old){ *old = newV ;}
				++fs;
			}
		}

protected:
	Game();

};




#endif
