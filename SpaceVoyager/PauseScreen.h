

#ifndef _PauseScreen_
#define _PauseScreen_


#include "Screens.h"

#pragma once

class PauseScreen : public Screens
{
      
      public:
      	PauseScreen(){};
      	~PauseScreen(){};



        virtual void display_screen();
        virtual void keyboard_screen(unsigned char key , int x , int y);
		virtual void keyboard_screen_sp(int& key,int& x,int& y);
        virtual void timer_screen(int t);
        virtual void idle_screen();
        virtual void reshape(int& w , int& h);
        virtual void loadObjects(); 

};





#endif
