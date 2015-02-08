

#ifndef _GameScreen_
#define _GameScreen_


#include "Screens.h"
#include "ISceneNode.h"
#include "GameStateManager.h"

#pragma once

class GameScreen : public Screens
{
      
 public:
 
	 GameScreen();
	 ~GameScreen();

	
        virtual void display_screen();
        virtual void keyboard_screen(unsigned char& key , int& x , int& y);
        virtual void timer_screen(int t);
        virtual void idle_screen();
        virtual void keyboard_screen_sp(int& key , int& x , int& y);
        virtual void loadObjects();
        virtual void reshape(int& w , int& h); 


};





#endif
