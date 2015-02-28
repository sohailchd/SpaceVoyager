

#ifndef _SplashScreen_
#define _SplashScreen_


#include "Screens.h"
#include "SoundManager.h"
#include "IEntityManager.h"

#pragma once

class SplashScreen : public Screens
{
      
      public:
		  SplashScreen(){
			  smngr = new SoundManager();
		  };
      	~SplashScreen(){};



        virtual void display_screen();
        virtual void keyboard_screen(unsigned char key , int x , int y);
        virtual void timer_screen(int t);
        virtual void idle_screen();
        virtual void reshape(int& w , int& h);
        virtual void loadObjects(); 

private:
	SoundManager* smngr;
		 
};





#endif
