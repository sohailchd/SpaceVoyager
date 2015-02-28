

#ifndef _MenuScreen_
#define _MenuScreen_


#include "Screens.h"
#include "IEntityManager.h"

#pragma once

class MenuScreen : public Screens
{
      
      public:
      	MenuScreen();
		~MenuScreen();


        virtual void display_screen();
        virtual void keyboard_screen(unsigned char& key , int& x , int& y);
        virtual void timer_screen(int t);
        virtual void idle_screen();
        virtual void loadObjects(); 
        virtual void reshape(int& w , int& h);
		virtual void keyboard_screen_sp(int& key,int& x,int& y);
        
        enum MenuStates { _start , _exit , _about };
        MenuStates _menu_current_state;
		bool isLoading;
		void draw_light_shade();
		//bool setState;
		float loadTimer;
};





#endif
