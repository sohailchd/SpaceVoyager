

#ifndef _RetryScreen_
#define _RetryScreen_


#include "Screens.h"
#include "SoundManager.h"
#include "IEntityManager.h"

#pragma once

class RetryScreen : public Screens
{
      
      public:
		  RetryScreen();
      	~RetryScreen();



		virtual void display_screen();
        virtual void keyboard_screen(unsigned char& key , int& x , int& y);
		virtual void keyboard_screen_sp(int& key,int& x,int& y);
        virtual void timer_screen(int t);
        virtual void idle_screen();
        virtual void loadObjects(); 
        virtual void reshape(int& w , int& h);

	
		        bool	sceneInit;

private:
	SoundManager* smngr;
		 
};





#endif
