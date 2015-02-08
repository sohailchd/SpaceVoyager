

#ifndef _MenuScreen_
#define _MenuScreen_


#include "Screens.h"
#include "IEntityManager.h"

#pragma once

class MenuScreen : public Screens
{
      
      public:
      	MenuScreen(){
      		_menu_current_state = _start;
			
      	};
      	~MenuScreen(){};



        virtual void display_screen();
        virtual void keyboard_screen(unsigned char& key , int& x , int& y);
        virtual void timer_screen(int t);
        virtual void idle_screen();
        virtual void loadObjects(); 
        virtual void reshape(int& w , int& h);

        
        enum MenuStates { _start , _exit , _about };
        MenuStates _menu_current_state;

		
};





#endif
